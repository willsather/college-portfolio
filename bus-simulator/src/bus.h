/**
 * @file bus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_H_
#define SRC_BUS_H_

#include <iostream>
#include <list>
#include <string>

#include "src/data_structs.h"
#include "src/IObservable.h"
#include "src/ibus.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class Bus : public IBus {
 public:
  Bus(std::string name, Route * out, Route * in, int capacity = 60,
      double speed = 1);
  bool IsTripComplete() override;
  int LoadPassenger(Passenger *) override;  // returning revenue delta
  bool Move() override;
  void Update() override;
  void Report(std::ostream&) override;

  // Vis Getters
  void UpdateBusData() override;
  BusData GetBusData() const override;
  std::string GetName() const override { return name_; }
  Stop * GetNextStop() const override { return next_stop_; }
  size_t GetNumPassengers() const override { return passengers_.size(); }
  int GetCapacity() const override { return passenger_max_capacity_; }
  bool outboundDirection() override { return outboundDirection_; }

 protected:
  int UnloadPassengers();  // returning revenue delta
  // bool Refuel();
  PassengerUnloader * unloader_;
  PassengerLoader * loader_;
  std::list<Passenger *> passengers_;
  int passenger_max_capacity_;
  // double revenue_; // revenue collected from passengers, doesn't include
                      // passengers who pay on deboard
  // double fuel_;   // may not be necessary for our simulation
  // double max_fuel_;
  std::string name_;
  double speed_;  // could also be called "distance travelled in one time step"
  Route * outgoing_route_;
  Route * incoming_route_;
  double distance_remaining_;  // when negative?, unload/load procedure occurs
                              // AND next stop set
  Stop * next_stop_;
  // bool trip_complete_;  // [DERIVED data] when BOTH routes are at end, trip
  // is complete
  // Vis data for bus
  BusData bus_data_;
  bool outboundDirection_;  // Used for decorator
  int total_passengers;
};
#endif  // SRC_BUS_H_
