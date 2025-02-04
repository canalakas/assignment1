#ifndef VEHICLE_H
#define VEHICLE_H

#include <GL/glew.h>
#include "game/GameObject.h"

class Vehicle : public GameObject {
protected:
    float speed;
    bool direction;
    GLuint shaderProgram;
    float color[3];

public:
    Vehicle(float x, float y, float speed, float width, float height, bool direction, GLuint shaderProgram);
    virtual ~Vehicle();

    virtual void draw() = 0;
    void update();
    bool isOutOfBounds();
};

#endif
