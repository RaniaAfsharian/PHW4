#ifndef SPEED_LIMIT_ZONE_H
#define SPEED_LIMIT_ZONE_H

#include "TrafficElement.h"

class SpeedLimitZone : public TrafficElement {
private:
    int limit;

public:
    SpeedLimitZone(int speedLimit);
    
    bool allows(const Vehicle& vehicle) const override;
    void printRule() const override;
    std::string getType() const override { return "SpeedLimitZone"; }
    
    int getLimit() const;
};

#endif
