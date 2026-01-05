#include "SpeedLimitZone.h"
#include <iostream>

SpeedLimitZone::SpeedLimitZone(int speedLimit) : limit(speedLimit) {}

bool SpeedLimitZone::allows(const Vehicle& vehicle) const {
    if (vehicle.getPriority() >= 3) {
        return true;
    }

    return vehicle.getSpeed() <= limit;
}

void SpeedLimitZone::printRule() const {
    std::cout << " Speed Limit Zone: Max " << limit << " km/h." << std::endl;
}

int SpeedLimitZone::getLimit() const { return limit; }