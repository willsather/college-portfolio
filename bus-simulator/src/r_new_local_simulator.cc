/**
 * @file r_new_local_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/r_new_local_simulator.h"

#include <vector>
#include <list>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/rtest_passenger_generator.h"

bool rNewLocalSimulator::Start() {
  simulation_time_elapsed_ = 0;  // init, but also allows restart

  // int num_round_trips = 10;
  int num_round_trips = 1;
  for (int i = 0; i < num_round_trips; i++) {
    time_since_last_bus_generation_.push_back(0);
  }

  Stop ** CC_EB_stops = new Stop *[4];
  Stop ** CC_WB_stops = new Stop *[5];
  std::list<Stop *> CC_EB_stops_list;
  std::list<Stop *> CC_WB_stops_list;

  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...

  // Replace with new stops from iteration 1

  // CC Eastbound stops
  Stop * stop_CC_EB_1 = new Stop(0, 44.973580, -93.235071);  // Coffman
  Stop * stop_CC_EB_2 = new Stop(1, 44.984630, -93.186352);  // St. Paul Student Center

  // CC Westbound stops
  Stop * stop_CC_WB_1 = new Stop(0, 44.984630, -93.186352);  // St. Paul Student Center
  Stop * stop_CC_WB_2 = new Stop(1, 44.973580, -93.235071);  // Coffman

  CC_EB_stops_list.push_back(stop_CC_EB_1);
  CC_EB_stops[0] = stop_CC_EB_1;
  CC_EB_stops_list.push_back(stop_CC_EB_2);
  CC_EB_stops[1] = stop_CC_EB_2;

  CC_WB_stops_list.push_back(stop_CC_WB_1);
  CC_WB_stops[0] = stop_CC_WB_1;
  CC_WB_stops_list.push_back(stop_CC_WB_2);
  CC_WB_stops[1] = stop_CC_WB_2;


  double * CC_EB_distances = new double[2];
  double * CC_WB_distances = new double[2];
  CC_EB_distances[0] = 19;
  CC_EB_distances[1] = 19;

  CC_WB_distances[0] = 19;
  CC_WB_distances[1] = 19;



  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.2); // Coffman
  CC_EB_probs.push_back(.2); // St. Paul Student Center2

  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.2); //post-transit
  CC_WB_probs.push_back(.2); //pre-transit


  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...
  //RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  //RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);

 RtestPassengerGenerator * CC_EB_generator = new RtestPassengerGenerator (CC_EB_probs, CC_EB_stops_list);
 RtestPassengerGenerator * CC_WB_generator = new RtestPassengerGenerator (CC_WB_probs, CC_WB_stops_list);

  //Test to ensure generators are working
  //Helpful for debugging
  //CC_EB_generator.GeneratePassengers();
  //CC_WB_generator.GeneratePassengers();

  //Again, MUST be dynamic...
  //Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 8, &CC_EB_generator);
  //Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 9, &CC_WB_generator);

  Route * CC_EB = new Route("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 2, CC_EB_generator);
  Route * CC_WB = new Route("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 2, CC_WB_generator);

  prototype_routes_.push_back(CC_EB);
  prototype_routes_.push_back(CC_WB);

  prototype_routes_[0]->Report(std::cout);
  prototype_routes_[1]->Report(std::cout);

  bus_counters_.push_back(10000);

  //This will eventually be replaced by configuration/command line argument
  bus_start_timings_.push_back(10);

  // Do we want a bus on start? Or let the update handle this?
  // active_buses_.push_back(new Bus(std::to_string(bus_counters_[0]),
  //   prototype_routes[0].Clone(), prototype_routes[1].Clone(), 60, 1));
  // bus_counters_[0]++;

  return true;
}

bool rNewLocalSimulator::Update() {
  // increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;

  // various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
                                                     prototype_routes_.begin();

  // increase each time since last bus
  // various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
      it != time_since_last_bus_generation_.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
    (*it)++;

    // if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      // create a new bus! routes are:
      // prototype_routes_[index * 2] & prototype_routes_[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;

      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  // for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    (*bus_iter)->Report(std::cout);

    //REQUIRES USE OF IsTripComplete, which was not required
    //Buses which are "done" will just keep having Update() called
    //  Students MAY need to deal with this, not sure yet...
    // remove bus if trip is complete
    //if ((*bus_iter)->IsTripComplete()) {
    //  bus_iter = active_buses_.erase(bus_iter);
    //  bus_iter--;
    //}
  }

  // for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
      route_iter != prototype_routes_.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }

  return true;
}
