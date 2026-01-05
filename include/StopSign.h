#ifndef STOP_SIGN_H
#define STOP_SIGN_H

#include "TrafficElement.h"

class StopSign : public TrafficElement {
public:
    bool allows(const Vehicle& vehicle) const override;
    void printRule() const override;
    std::string getType() const override { return "StopSign"; }
};

#endif
