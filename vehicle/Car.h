#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(float x, float y, float speed, bool direction, GLuint shaderProgram);
    void draw() override;
};

#endif // CAR_H
