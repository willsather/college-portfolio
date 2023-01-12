#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <string>

#include "r_new_local_simulator.h"

int main() {

  int rounds = 25; //Number of rounds of generation to simulate in test

  srand((long)1); //Seed the random number generator with the same seed every time!

  rNewLocalSimulator my_sim;
  std::cout << std::endl;
  std::cout << "/****************************" << std::endl;
  std::cout << "         STARTING MY " << std::endl;
  std::cout << "       NEW SIMULATION" << std::endl;
  std::cout << "****************************/" << std::endl;

  my_sim.Start();

  std::cout << std::endl;
  std::cout << "/***************************" << std::endl;
  std::cout << "           BEGIN" << std::endl;
  std::cout << "          UPDATING" << std::endl;
  std::cout << "***************************/" << std::endl;

  for (int i = 0; i < rounds; i++) {
	  my_sim.Update();
  }

  std::cout << std::endl;
  std::cout << "/********************************" << std::endl;
  std::cout << "        NEW VERSION OF " << std::endl;
  std::cout << "      SIMULATION COMPLETE" << std::endl;
  std::cout << "********************************/" << std::endl;


  return 0;
}
