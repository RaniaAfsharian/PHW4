#ifndef VEHICLE_H
#define VEHICLE_H 

#include <string>
#include <iostream>

class TrafficElement;

class Vehicle {
protected:
    int id;
    std::string plate;
    int speed;
    
public:
    static int totalVehicles;

    Vehicle(int id, std::string plate, int speed);
    virtual ~Vehicle();

    int getSpeed() const;
    void setSpeed(int s);
    std::string getPlate() const;

    virtual bool canMove(const TrafficElement& element) const = 0;
    virtual void move();
    virtual void printStatus() const;
    virtual int getPriority() const = 0; 

    Vehicle& operator+(int increase);
    
    bool operator<(const Vehicle& other) const;
};

#endif
