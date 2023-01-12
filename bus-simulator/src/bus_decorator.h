// OUTBUND MAROON = Color(111, 19, 28, 255);
// INBOUND GOLD = Color(249, 215, 115, 255);

/**
 * @file bus_decorator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_BUS_DECORATOR_H_
#define SRC_BUS_DECORATOR_H_

#include <vector>
#include <iostream>
#include <string>

#include "src/bus.h"
#include "src/data_structs.h"

class BusDecorator : public IBus {
 public:
  explicit BusDecorator(IBus*);
  bool IsTripComplete() override;
  int LoadPassenger(Passenger *) override;
  bool Move() override;
  void Update() override;
  void Report(std::ostream&) override;
  void UpdateBusData() override;
  std::string GetName() const override;
  Stop * GetNextStop() const override;
  size_t GetNumPassengers() const override;
  int GetCapacity() const override;
  bool outboundDirection() override;

  /** @brief
  This Redecorate function takes in a bus pointer
  and changes the bus's color to whatever color is
  appropriate.  Once that occurs, then it determines
  the proper alpha value (total opacity) based
  on number of passengers on the bus */
  BusData GetBusData() const override;

 protected:
  IBus* busToDecorate;
};
#endif  // SRC_BUS_DECORATOR_H_
