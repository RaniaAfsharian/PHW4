#ifndef BUS_H
#define BUS_H

#include "Vehicle.h"
#include "TrafficElement.h"

class Bus : public Vehicle {
public:
    Bus(int id, std::string plate, int speed);
    
    bool canMove(const TrafficElement& element) const override;
    void printStatus() const override;
    int getPriority() const override;
};

#endif
