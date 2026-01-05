#include <iostream>
#include <vector>
#include "Car.h"
#include "Bus.h"
#include "EmergencyVehicle.h"
#include "TrafficLight.h"
#include "StopSign.h"
#include "SpeedLimitZone.h"
#include "Intersection.h"

int main() {
    std::cout << " **********  CITY TRAFFIC CONTROL SYSTEM   **********    \n";

    Car car1(101, "CAR-111", 50);
    Bus bus1(202, "BUS-222", 40);
    EmergencyVehicle ambulance(911, "EMG-999", 80);

    std::cout << "\nEvent Car accelerates..." << std::endl;
    car1 + 20; 
    car1.printStatus();

    std::cout << "\nEvent Checking Priorities..." << std::endl;
    if (car1 < ambulance) {
        std::cout << "-> Ambulance has higher priority than Car." << std::endl;
    }

    Intersection downtownIntersection;

    TrafficLight* mainLight = new TrafficLight(RED);
    SpeedLimitZone* schoolZone = new SpeedLimitZone(60);

    downtownIntersection.addRule(mainLight);
    downtownIntersection.addRule(schoolZone);

    downtownIntersection.addVehicle(&car1);
    downtownIntersection.addVehicle(&bus1);
    downtownIntersection.addVehicle(&ambulance);

    downtownIntersection.simulate();

    std::cout << "\nEvent Traffic Light turns GREEN..." << std::endl;
    mainLight->setState(GREEN);
    
    if (*mainLight == GREEN) {
        std::cout << "-> Light confirms it is GREEN." << std::endl;
    }

    downtownIntersection.simulate();

    delete mainLight;
    delete schoolZone;

    return 0;
}
