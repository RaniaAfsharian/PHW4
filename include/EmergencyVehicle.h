#ifndef EMERGENCY_VEHICLE_H
#define EMERGENCY_VEHICLE_H

#include "Vehicle.h"
#include "TrafficElement.h"

class EmergencyVehicle : public Vehicle {
public:
    EmergencyVehicle(int id, std::string plate, int speed);
    
    bool canMove(const TrafficElement& element) const override;
    void printStatus() const override;
    int getPriority() const override;
};

#endif
