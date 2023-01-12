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

#include "../src/stop.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"


using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class RouteTests : public ::testing::Test {
protected:
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

  virtual void SetUp() {

    // Set two new stops
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

// Tests Route Constructor
// Also test Getters/Setters
TEST_F(RouteTests, Constructor) {

  EXPECT_EQ(route1->GetName(), "Route1Name");
  EXPECT_EQ(route1->GetStops(), stopsList);

  EXPECT_EQ(route2->GetName(), "Route2Name");
  EXPECT_EQ(route2->GetStops(), stopsList);

};

// Tests Clone Function
TEST_F(RouteTests, Clone) {
  routeC = route1->Clone();

  EXPECT_EQ(routeC->GetName(), route1->GetName());
  EXPECT_EQ(routeC->GetStops(), route1->GetStops());
  EXPECT_EQ(routeC->GetTotalRouteDistance(), route1->GetTotalRouteDistance());


};

// Tests IsAtEnd Function
TEST_F(RouteTests, IsAtEnd) {

  EXPECT_EQ(route1->IsAtEnd(), false);
  route1->ToNextStop();
  route1->ToNextStop();
  EXPECT_EQ(route1->IsAtEnd(), true);

  EXPECT_EQ(route2->IsAtEnd(), false);
  route2->ToNextStop();
  route2->ToNextStop();
  EXPECT_EQ(route2->IsAtEnd(), true);

};
