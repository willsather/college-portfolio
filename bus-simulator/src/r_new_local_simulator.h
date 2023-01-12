/**
 * @file r_fast_local_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef SRC_R_NEW_LOCAL_SIMULATOR_H_
#define SRC_R_NEW_LOCAL_SIMULATOR_H_

#include <vector>
#include <string>
#include "src/simulator.h"

class rNewLocalSimulator : public Simulator {
 public:
   /** @brief
   This function starts the simulation
   for the regression test.
   */
  bool Start() override;

  /** @brief
  This function acts as the update function
  from the bus class, but this version is
  for the simulation for the regression test. 
  */
  bool Update() override;
 private:
  std::vector<int> bus_counters_;
  std::vector<int> bus_start_timings_;
  std::vector<int> time_since_last_bus_generation_;
  int simulation_time_elapsed_;
};

#endif  // SRC_R_NEW_LOCAL_SIMULATOR_H_
