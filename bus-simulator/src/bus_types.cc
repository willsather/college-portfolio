/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus_types.h"
#include "src/bus.h"

/****************************************/
/* SMALL BUS IMPLEMENTATION             */
/****************************************/
SmallBus::SmallBus(std::string name, Route * out, Route * in,
         double speed): Bus(name, out, in, 30, speed) {}

void SmallBus::Report(std::ostream& out) {
    out << "Name: " << name_ << std::endl;
    out << "Bus Type: Small Bus (30)" << std::endl;
    out << "Speed: " << speed_ << std::endl;
    out << "Distance to next stop: " << distance_remaining_ << std::endl;
    out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
         it != passengers_.end(); it++) {
      (*it)->Report(out);
  }
}

/****************************************/
/* REGULAR BUS IMPLEMENTATION           */
/****************************************/
RegularBus::RegularBus(std::string name, Route * out, Route * in,
         double speed): Bus(name, out, in, 60, speed) {}


void RegularBus::Report(std::ostream& out) {
    out << "Name: " << name_ << std::endl;
    out << "Bus Type: Regular Bus (60)" << std::endl;
    out << "Speed: " << speed_ << std::endl;
    out << "Distance to next stop: " << distance_remaining_ << std::endl;
    out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
         it != passengers_.end(); it++) {
      (*it)->Report(out);
  }
}

/****************************************/
/* LARGE BUS IMPLEMENTATION             */
/****************************************/
LargeBus::LargeBus(std::string name, Route * out, Route * in, double speed):
  Bus(name, out, in, 90, speed) {}

void LargeBus::Report(std::ostream& out) {
    out << "Name: " << name_ << std::endl;
    out << "Bus Type: Large Bus (90)" << std::endl;
    out << "Speed: " << speed_ << std::endl;
    out << "Distance to next stop: " << distance_remaining_ << std::endl;
    out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
    for (std::list<Passenger *>::iterator it = passengers_.begin();
         it != passengers_.end(); it++) {
      (*it)->Report(out);
  }
}
