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

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/

class StopTests : public ::testing::Test {
protected:
  Stop* stop;
  Stop* stop1;

  virtual void SetUp() {
    stop = new Stop(12);
    stop1 = new Stop(12, 45.123456, -93.654321);

  }

  virtual void TearDown() {
    delete stop;
    delete stop1;

    stop = NULL;
    stop1 = NULL;

  }
};

/*******************************************************************************
 * Test Case
 ******************************************************************************/

// Tests Stop Constructor
TEST_F(StopTests, Constructor) {

  // Check stop coordinates
  EXPECT_EQ(stop->GetLongitude(), 44.973723);
  EXPECT_EQ(stop->GetLatitude(), -93.235365);

  // Check stop1 coordinates
  EXPECT_EQ(stop1->GetLongitude(), 45.123456);
  EXPECT_EQ(stop1->GetLatitude(), -93.654321);

  // Check Number of Passengers Present
  EXPECT_EQ(stop->GetNumPassengersPresent(), 0);
  EXPECT_EQ(stop1->GetNumPassengersPresent(), 0);

};
