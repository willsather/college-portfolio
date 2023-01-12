/**
 * @file bus_factory.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_FACTORY_H_
#define SRC_BUS_FACTORY_H_

#include <string>

#include "src/bus.h"
#include "src/bus_types.h"

class BusFactory {
 public:
   /** @brief
   This generate function uses the parameters
   of a bus, as well as a randomly generated
   integer which determines the bus size, to
   return a pointer to a new bus.  This function
   is used by visualization_simulator.cc
   */
  static Bus * generate(std::string, Route *, Route *, double);
 private:
  static int state_;
};
#endif  // SRC_BUS_FACTORY_H_
