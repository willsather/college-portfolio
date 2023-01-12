/**
 * @file bus_types.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_TYPES_H_
#define SRC_BUS_TYPES_H_

#include <iostream>
#include <list>
#include <string>

#include "src/bus.h"
#include "src/bus_types.h"

#include "src/passenger.h"
#include "src/passenger_loader.h"
#include "src/passenger_unloader.h"
#include "src/route.h"
#include "src/stop.h"
#include "src/ibus.h"

class PassengerUnloader;
class PassengerLoader;
class Route;
class Stop;
class Bus;
class IBus;

class SmallBus;
class RegularBus;
class LargeBus;

/** @ brief
This class represents a Small Bus, which
has a capacity of 30 people.  This class
inherits from Bus
*/
class SmallBus : public Bus {
 public:
  SmallBus(std::string, Route *, Route *, double);
  void Report(std::ostream&) override;
};

/** @ brief
This class represents a Regular Bus, which
has a capacity of 60 people.  This class
inherits from Bus
*/
class RegularBus : public Bus {
 public:
  RegularBus(std::string, Route *, Route *, double);
  void Report(std::ostream&) override;
};

/** @brief
This class represents a Large Bus, which
has a capacity of 90 people.  This class
inherits from Bus
*/
class LargeBus : public Bus {
 public:
  LargeBus(std::string, Route *, Route *, double);
  void Report(std::ostream&) override;
};
#endif  // SRC_BUS_TYPES_H_
