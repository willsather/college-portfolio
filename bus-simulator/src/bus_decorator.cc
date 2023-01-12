/**
 * @file bus_decorator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/bus_decorator.h"

BusDecorator::BusDecorator(IBus* bus):IBus() {
  busToDecorate = bus;
}

BusData BusDecorator::GetBusData() const {
  BusData dat = busToDecorate->GetBusData();

  // Color bus correctly
  if (busToDecorate->outboundDirection()) {
    // Bus is on outbound route - MAROON
    busToDecorate->changeColor(Color(111, 19, 28, 255));
    dat.color = Color(111, 19, 28, 255);

  } else {
    // Bus is on inbound route - GOLD
    busToDecorate->changeColor(Color(249, 215, 115, 255));
    dat.color = Color(249, 215, 115, 255);
  }

  // Properly set opacity of bus
  int num_passengers = busToDecorate->GetNumPassengers();

  if (num_passengers < 1) {
    busToDecorate->changeAlpha(75);
    dat.color.alpha = 75;

  } else if (num_passengers < 2) {
    busToDecorate->changeAlpha(100);
    dat.color.alpha = 100;

  } else if (num_passengers < 3) {
    busToDecorate->changeAlpha(150);
    dat.color.alpha = 150;

  } else if (num_passengers < 4) {
    busToDecorate->changeAlpha(175);
    dat.color.alpha = 175;

  } else if (num_passengers < 5) {
    busToDecorate->changeAlpha(200);
    dat.color.alpha = 200;

  } else if (num_passengers < 6) {
    busToDecorate->changeAlpha(225);
    dat.color.alpha = 225;
  }
  busToDecorate->UpdateBusData();
  std::cout << "Decorating Bus" << std::endl;
  return dat;
}


bool BusDecorator::IsTripComplete() {
  return busToDecorate->IsTripComplete();
}
int BusDecorator::LoadPassenger(Passenger * pass) {
  return busToDecorate->LoadPassenger(pass);
}

bool BusDecorator::Move() {
  return busToDecorate->Move();
}

void BusDecorator::Update() {
  busToDecorate->Update();
}

void BusDecorator::Report(std::ostream& os) {
  busToDecorate->Report(os);
}

void BusDecorator::UpdateBusData() {
  busToDecorate->UpdateBusData();
}

std::string BusDecorator::GetName() const {
  return busToDecorate->GetName();
}

Stop * BusDecorator::GetNextStop() const {
  return busToDecorate->GetNextStop();
}

size_t BusDecorator::GetNumPassengers() const {
  return busToDecorate->GetNumPassengers();
}

int BusDecorator::GetCapacity() const {
  return busToDecorate->GetCapacity();
}

bool BusDecorator::outboundDirection() {
  return busToDecorate->outboundDirection();
}
