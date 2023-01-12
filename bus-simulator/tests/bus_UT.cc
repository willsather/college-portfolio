/*
 * Students: Use this file as a guide to writing your own unit tests.
 * See the project instructions for more information on which classes
 * and methods must be tested.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger_unloader.h"
#include "../src/route.h"
#include "../src/stop.h"

#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class BusTests : public ::testing::Test {
protected:
  Passenger* passenger1;
  Passenger* passenger2;


  Stop* stop1;
  Stop* stop2;

  std::list<Stop*> stopsList;
  std::list<double> distancesList;

  Stop** stopsPointer;
  double* distancesPointer;

  Route* route1;
  Route* route2;
  Route* routeC;

  PassengerGenerator* passGen;

  Bus * bus1;
  Bus * bus2;

  virtual void SetUp() {

    // Create two new passengers
    passenger1 = new Passenger(11, "John Doe");
    passenger2 = new Passenger(12, "Apple Bee");

    // Create two new stops
    stop1 = new Stop(12);
    stop2 = new Stop(12, 45.123456, -93.654321);

    // Set up Stop list/pointer
    stopsPointer = new Stop*[2];
    stopsPointer[0] = stop1;
    stopsPointer[1] = stop2;
    stopsList.push_back(stop1);
    stopsList.push_back(stop2);

    // Set up Distances list/pointer
    distancesPointer = new double[2];
    distancesPointer[0] = 1.23;
    distancesPointer[1] = 4.56;
    distancesList.push_back(1.23);
    distancesList.push_back(4.56);

    // Instantiate new RnadomPassengerGenerator
    passGen = new RandomPassengerGenerator(distancesList, stopsList);

    // Create two new routes
    route1 = new Route("Route1Name", stopsPointer, distancesPointer, 2, passGen);
    route2 = new Route("Route2Name", stopsPointer, distancesPointer, 2, passGen);

    // Create new bus
    bus1 = new Bus("Bus1", route1, route2);
    bus2 = new Bus("Bus2", route1, route2, 25, 2);


  }

  virtual void TearDown() {

    delete stop1;
    delete stop2;

    stop1 = NULL;
    stop2 = NULL;

    delete passGen;
    delete route1;
    delete route2;
    delete bus1;

  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

// Tests Passenger Constructor
TEST_F(BusTests, Constructor) {

  EXPECT_EQ(bus1->GetName(), "Bus1");
  EXPECT_EQ(bus1->GetCapacity(), 60);

  EXPECT_EQ(bus2->GetName(), "Bus2");
  EXPECT_EQ(bus2->GetCapacity(), 25);

};

// Tests IsTripComplete Function
// Also tests Update Function
TEST_F(BusTests, IsTripComplete) {

  // Checks if Busses start completed
  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);

  // Move bus to first stop
  bus1->Update();
  bus2->Update();

  // Move bus to second stop
  bus1->Update();
  bus2->Update();

  // Check that Trip is Complete
  EXPECT_EQ(bus1->IsTripComplete(), true);
  EXPECT_EQ(bus2->IsTripComplete(), true);

};

// Tests LoadPassenger
TEST_F(BusTests, LoadPassenger) {

  // Checks bussess start empty
  EXPECT_EQ(bus1->GetNumPassengers(), 0);
  EXPECT_EQ(bus2->GetNumPassengers(), 0);

  // Load one passenger on bus1
  bus1->LoadPassenger(passenger1);

  // Load two passenger on bus2
  bus2->LoadPassenger(passenger1);
  bus2->LoadPassenger(passenger2);

  // Checks bussess start empty
  EXPECT_EQ(bus1->GetNumPassengers(), 1);
  EXPECT_EQ(bus2->GetNumPassengers(), 2);

};

// Tests Move Function
TEST_F(BusTests, Move) {

  // Checks if Busses start completed
  EXPECT_EQ(bus1->IsTripComplete(), false);
  EXPECT_EQ(bus2->IsTripComplete(), false);

  // Move busses to first stop
  bus1->Move();
  bus2->Move();

  // Move busses to second stop
  bus1->Move();
  bus2->Move();

  // Check that Trip is Complete
  EXPECT_EQ(bus1->IsTripComplete(), true);
  EXPECT_EQ(bus2->IsTripComplete(), true);

};


// Check Report Function
TEST_F(BusTests, Report) {

  std::string expected_output1 = "Name: Bus1";
  std::string expected_output2 = "Name: Bus2";

  testing::internal::CaptureStdout();
  bus1->Report(std::cout);
  std::string actual_output1 = testing::internal::GetCapturedStdout();
  int result1 = actual_output1.find(expected_output1);

  testing::internal::CaptureStdout();
  bus2->Report(std::cout);
  std::string actual_output2 = testing::internal::GetCapturedStdout();
  int result2 = actual_output2.find(expected_output2);

  EXPECT_GE(result1, 0);
  EXPECT_GE(result2, 0);

};
