/**
 * @file IBus.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_IBUS_H_
#define SRC_IBUS_H_

#include <iostream>
#include <string>
#include <list>

#include "src/data_structs.h"
#include "src/IObservable.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;

class IBus : public IObservable<BusData> {
 public:
  // Ibus();
  virtual bool IsTripComplete() = 0;
  virtual int LoadPassenger(Passenger *) = 0;
  virtual bool Move() = 0;
  virtual void Update() = 0;
  virtual void Report(std::ostream&) = 0;
  void changeColor(Color c) {bus_data_.color = c;}
  Color getColor() {return bus_data_.color; }
  void changeAlpha(int a) { bus_data_.color.alpha = a; }

  // Vis Getters
  virtual void UpdateBusData() = 0;
  virtual BusData GetBusData() const = 0;
  virtual std::string GetName() const = 0;
  virtual Stop* GetNextStop() const = 0;
  virtual size_t GetNumPassengers() const = 0;
  virtual int GetCapacity() const = 0;
  virtual bool outboundDirection() = 0;

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
#endif  // SRC_IBUS_H_
