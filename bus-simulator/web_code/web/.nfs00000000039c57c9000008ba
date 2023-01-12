
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>
#include <iostream>

#include "web_interface.h"
#include "config_manager.h"
#include "bus.h"
#include "route.h"
#include "bus_factory.h"
#include "util.h"
#include "file_writer.h"
#include "file_writer_manager.h"
#include "IObserver.h"
#include "IObservable.h"
#include "bus_decorator.h"
#include "ibus.h"

class Route;
class Bus;
class Stop;
//template class IObservable<BusData>;
//template class IObservable<StopData>;


class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Update();
        /** @brief
        This function is used to change the isPaused
        boolean and is the connection between the
        visualization_simulator and the web_code
        directory.
        */
        void Pause();

        /** @ brief
        This function is used to add a bus listener
        to the oberserver pattern using the
        RegisterOberserver function in IOobservable
        */

        void AddBusListener(std::string* id, IObserver<BusData>* observer);

        /** @ brief
        This function is used to add a stop listener
        to the oberserver pattern using the
        RegisterOberserver function in IOobservable
        */

        void AddStopListener(std::string* id, IObserver<StopData>* observer);

        /** @ brief
        This function is used to clear all bus listeners
        from the oberserver pattern using the
        ClearOberserver function in IOobservable
        */
        void ClearBusListeners();

        /** @ brief
        This function is used to clear all stop listeners
        from the oberserver pattern using the
        ClearOberserver function in IOobservable
        */
        void ClearStopListeners();


    private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;

        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<IBus *> busses_;

        int busId = 1000;
        bool isPaused;
};

#endif // VISUALIZATION_SIMULATOR_H_
