#include "StopSign.h"
#include <iostream>

bool StopSign::allows(const Vehicle& vehicle) const {

    return vehicle.getSpeed() < 5;
}

void StopSign::printRule() const {
    std::cout << " Stop Sign: Must slow down to pass." << std::endl;
}
