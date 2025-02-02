#include "Vehicle.h"
#include <cstdlib>

Vehicle::Vehicle(float x, float y, float speed, float width, float height, bool direction, GLuint shaderProgram)
    : GameObject(x, y, width, height), speed(speed), direction(direction), shaderProgram(shaderProgram) {

    color[0] = 0.2f + static_cast<float>(rand() % 80) / 100.0f; // R
    color[1] = 0.2f + static_cast<float>(rand() % 80) / 100.0f; // G
    color[2] = 0.2f + static_cast<float>(rand() % 80) / 100.0f; // B
}

Vehicle::~Vehicle() {}

void Vehicle::update() {
    if (direction) {
        x += speed; // Sağa hareket
    } else {
        x -= speed; // Sola hareket
    }
}

bool Vehicle::isOutOfBounds() {
    return (x > 1.1f || x < -1.1f);
}
