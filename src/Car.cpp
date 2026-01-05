#include "Car.h"
#include <iostream>

Car::Car(int id, std::string plate, int speed) : Vehicle(id, plate, speed) {}

bool Car::canMove(const TrafficElement& element) const {
    return element.allows(*this);
}

void Car::printStatus() const {
    std::cout << " Car ";
    Vehicle::printStatus();
}

int Car::getPriority() const {
    return 1;
}
