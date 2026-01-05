#include "Vehicle.h"

int Vehicle::totalVehicles = 0;

Vehicle::Vehicle(int id, std::string plate, int speed) 
    : id(id), plate(plate), speed(speed) {
    totalVehicles++; 
}

Vehicle::~Vehicle() {
    totalVehicles--; 
}

int Vehicle::getSpeed() const { return speed; }
void Vehicle::setSpeed(int s) { speed = s; }
std::string Vehicle::getPlate() const { return plate; }

void Vehicle::move() {
    std::cout << "Vehicle " << plate << " is moving at " << speed << " km/h." << std::endl;
}

void Vehicle::printStatus() const {
    std::cout << "Vehicle " << id << " Plate: " << plate << ", Speed: " << speed << std::endl;
}

Vehicle& Vehicle::operator+(int increase) {
    this->speed += increase;
    return *this;
}

bool Vehicle::operator<(const Vehicle& other) const {
    return this->getPriority() < other.getPriority();
}