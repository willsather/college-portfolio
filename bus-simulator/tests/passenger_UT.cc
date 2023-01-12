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

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/passenger.h"
#include "../src/stop.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class PassengerTests : public ::testing::Test {
protected:
  PassengerLoader* pass_loader;
  PassengerUnloader* pass_unloader;
  Passenger *passenger, *passenger1, *passenger2;

  virtual void SetUp() {
    passenger = new Passenger();
    passenger1 = new Passenger(11, "John Doe");
    passenger2 = new Passenger(12, "Apple Bee");

    pass_loader = new PassengerLoader();
    pass_unloader = new PassengerUnloader();
  }

  virtual void TearDown() {
    delete passenger;
    delete passenger1;
    delete passenger2;

    delete pass_loader;
    delete pass_unloader;

    passenger = NULL;
    passenger1 = NULL;
    passenger2 = NULL;

    pass_loader = NULL;
    pass_unloader = NULL;
  }
};


/*******************************************************************************
 * Test Cases
 ******************************************************************************/

// Tests Passenger Constructor and GetOnBus()
TEST_F(PassengerTests, Constructor) {
  EXPECT_EQ(passenger->IsOnBus(), false);
  passenger->GetOnBus();
  EXPECT_EQ(passenger->IsOnBus(), true);
};


// Tests TimeOnBus Function
TEST_F(PassengerTests, TimeOnBus) {
  passenger1->GetOnBus();
  for (int i=0; i<5; i++) { passenger1->Update(); }

  EXPECT_EQ(passenger1->GetTotalWait(), 6);
};

// Tests Update Function
TEST_F(PassengerTests, Update) {
  passenger1->GetOnBus();

  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 2);
  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 3);
  passenger1->Update();
  EXPECT_EQ(passenger1->GetTotalWait(), 4);
};

// Tests GetDestination Function
TEST_F(PassengerTests, GetDestination) {
  EXPECT_EQ(passenger1->GetDestination(), 11);
  EXPECT_EQ(passenger2->GetDestination(), 12);
};



// Check Report Function
TEST_F(PassengerTests, NameCheck) {

  std::string expected_output1 = "Name: John Doe";
  std::string expected_output2 = "Name: Apple Bee";

  testing::internal::CaptureStdout();
  passenger1->Report(std::cout);
  std::string actual_output1 = testing::internal::GetCapturedStdout();
  int result1 = actual_output1.find(expected_output1);

  testing::internal::CaptureStdout();
  passenger2->Report(std::cout);
  std::string actual_output2 = testing::internal::GetCapturedStdout();
  int result2 = actual_output2.find(expected_output2);

  EXPECT_GE(result1, 0);
  EXPECT_GE(result2, 0);

};
