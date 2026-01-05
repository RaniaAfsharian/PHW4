#include "Bus.h"
#include <iostream>

Bus::Bus(int id, std::string plate, int speed) : Vehicle(id, plate, speed) {}

bool Bus::canMove(const TrafficElement& element) const {
    return element.allows(*this);
}

void Bus::printStatus() const {
    std::cout << " Bus ";
    Vehicle::printStatus();
}

int Bus::getPriority() const {
    return 2; 
}
