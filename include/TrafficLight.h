#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include "TrafficElement.h"

enum LightState { RED, YELLOW, GREEN };

class TrafficLight : public TrafficElement {
private:
    LightState state;

public:
    TrafficLight(LightState initialState);
    
    bool allows(const Vehicle& vehicle) const override;
    void printRule() const override;
    std::string getType() const override { return "TrafficLight"; }
    
    LightState getState() const;
    void setState(LightState s);
    
    bool operator==(LightState otherState) const;
};

#endif
