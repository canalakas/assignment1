#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(float x, float y, float speed, bool direction, GLuint shaderProgram);
    void draw() override;
};

#endif // TRUCK_H
