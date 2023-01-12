#include <vector>
#include <random>

#include "visualization_simulator.h"

VisualizationSimulator::VisualizationSimulator(WebInterface* webI, ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {

}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings, const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }

}

void VisualizationSimulator::Update() {

    if (isPaused) {return;}

    /* Code used for Iteration 1 Bus Factory
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist1(1, 3);
    int rand_int = dist1(rng);
    */

    simulationTimeElapsed_++;

    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    BusFactory busFactory;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {

            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];

            // Genereate IBus
            IBus * currentIBus = busFactory.generate(std::to_string(busId), outbound->Clone(), inbound->Clone(), 1);

            // Decorate Bus to instantalize
            BusDecorator busDec(currentIBus);
            currentIBus->changeColor(busDec.GetBusData().color);

            // Add bus to vector of IBus's
            busses_.push_back(currentIBus);

            // Old Code
            //busses_.push_back(busFactory.generate(std::to_string(busId), outbound->Clone(), inbound->Clone(), 1));

            busId++;

            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        // Decorate the bus to update opacity
        BusDecorator busDecor(busses_[i]);
        busDecor.GetBusData();

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);

            // New Singleton Pattern Code
            /// Bus Trip is complete:
            Util util;
            FileWriterManager fwm;
            FileWriter fw = fwm.GetInstance();

            std::ostringstream ss;
            busses_[i]->Report(ss);

            std::vector<std::string> retVec = util.processOutput(&ss);
            fw.Write("BusData.csv", retVec);

            // Original Code
            busses_.erase(busses_.begin() + i);
            continue;
        }


        webInterface_->UpdateBus(busses_[i]->GetBusData());

        busses_[i]->Report(std::cout);
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }

}

void VisualizationSimulator::Pause() {
  isPaused = !isPaused;
}

void VisualizationSimulator::ClearBusListeners() {
  for (int i = static_cast<int>(busses_.size())-1; i>=0; i--) {
    busses_[i]->ClearObservers();
  }
}

void VisualizationSimulator::ClearStopListeners() {
  for (std::vector<Route*>::iterator rut = prototypeRoutes_.begin(); rut != prototypeRoutes_.end(); rut++) {
    std::list<Stop*> stops = (*rut)->GetStops();
    for (std::list<Stop*>::iterator iter = stops.begin(); iter != stops.end(); iter++) {
        (*iter)->ClearObservers();
      }
    }
  }

void VisualizationSimulator::AddBusListener(std::string* id, IObserver<BusData>* observer) {
  for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
    if (busses_[i]->GetName() == (*id)) {
      busses_[i]->RegisterObserver(observer);
    }
  }
}

void VisualizationSimulator::AddStopListener(std::string* id, IObserver<StopData>* observer) {

  for (std::vector<Route*>::iterator rut = prototypeRoutes_.begin(); rut != prototypeRoutes_.end(); rut++) {
    std::list<Stop*> stops = (*rut)->GetStops();
    for (std::list<Stop*>::iterator iter = stops.begin(); iter != stops.end(); iter++) {
      // Comparing INT to CASTED INT
      if ( (*iter)->GetId() == std::stoi((*id)) ) {
        (*iter)->RegisterObserver(observer);
        return;
      }
    }
  }
}
