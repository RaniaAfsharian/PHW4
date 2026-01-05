#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include "Vehicle.h"
#include "TrafficElement.h"

class Intersection {
private:
    std::vector<Vehicle*> vehicles;
    std::vector<TrafficElement*> rules;

public:
    void addVehicle(Vehicle* v);
    void addRule(TrafficElement* e);
    
    void simulate();
    void printStatus() const;
};

#endif
