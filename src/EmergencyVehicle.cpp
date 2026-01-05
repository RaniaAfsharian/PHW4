#include "EmergencyVehicle.h"
#include <iostream>

EmergencyVehicle::EmergencyVehicle(int id, std::string plate, int speed) 
    : Vehicle(id, plate, speed) {}

bool EmergencyVehicle::canMove(const TrafficElement& element) const {
    return element.allows(*this);
}

void EmergencyVehicle::printStatus() const {
    std::cout << " Emergency ";
    Vehicle::printStatus();
}

int EmergencyVehicle::getPriority() const {
    return 3; 
}