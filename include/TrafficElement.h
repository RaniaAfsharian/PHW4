#ifndef TRAFFIC_ELEMENT_H
#define TRAFFIC_ELEMENT_H

#include "Vehicle.h"

class TrafficElement {
public:
    virtual ~TrafficElement() {}
    virtual bool allows(const Vehicle& vehicle) const = 0;
    virtual void printRule() const = 0;
    
    virtual std::string getType() const = 0;
};

#endif
