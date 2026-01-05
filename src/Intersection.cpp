#include "Intersection.h"
#include <iostream>
#include <algorithm> 

void Intersection::addVehicle(Vehicle* v) {
    vehicles.push_back(v);
}

void Intersection::addRule(TrafficElement* e) {
    rules.push_back(e);
}

void Intersection::simulate() {
    std::cout << "\n--- Starting Intersection Simulation ---" << std::endl;
    std::cout << "Total Vehicles in City: " << Vehicle::totalVehicles << "\n" << std::endl;

    for (const auto& rule : rules) {
        rule->printRule();
    }
    std::cout << "---------------------------------------" << std::endl;

    for (auto v : vehicles) {
        v->printStatus();
        
        bool canPassAll = true;
        for (const auto& rule : rules) {
            if (!v->canMove(*rule)) {
                std::cout << " Stopped by traffic rule." << std::endl;
                canPassAll = false;
                break; 
            }
        }

        if (canPassAll) {
            std::cout << " Clear to move! ";
            v->move();
        }
        std::cout << std::endl;
    }
}

void Intersection::printStatus() const {
    std::cout << "\n=== Intersection Status ===" << std::endl;
    std::cout << "Number of vehicles waiting: " << vehicles.size() << std::endl;
    std::cout << "Number of active traffic rules: " << rules.size() << std::endl;
    
    int moving = 0;
    for (const auto& v : vehicles) {
        bool canMove = true;
        for (const auto& rule : rules) {
            if (!v->canMove(*rule)) {
                canMove = false;
                break;
            }
        }
        if (canMove) moving++;
    }
    
    std::cout << "Vehicles allowed to move: " << moving << std::endl;
    if (moving == 0) {
        std::cout << ">> Intersection is completely blocked! <<\n";
    } else if (moving == vehicles.size()) {
        std::cout << ">> All vehicles can move freely. <<\n";
    }
    std::cout << "===========================\n" << std::endl;
}
