#include "TrafficLight.h"
#include <iostream>

TrafficLight::TrafficLight(LightState initialState) : state(initialState) {}

bool TrafficLight::allows(const Vehicle& vehicle) const {
    if (vehicle.getPriority() >= 3) {
        return true;
    }

    if (state == GREEN) return true;
    if (state == YELLOW) return vehicle.getSpeed() > 60; 
    return false; 
}

void TrafficLight::printRule() const {
    std::string s = (state == RED) ? "RED" : (state == YELLOW) ? "YELLOW" : "GREEN";
    std::cout << " Traffic Light is " << s << std::endl;
}

LightState TrafficLight::getState() const { return state; }
void TrafficLight::setState(LightState s) { state = s; }

bool TrafficLight::operator==(LightState otherState) const {
    return this->state == otherState;
}