#include "game/GameObject.h"

GameObject::GameObject(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height) {}

float GameObject::getX() const { return x; }
float GameObject::getY() const { return y; }
float GameObject::getWidth() const { return width; }
float GameObject::getHeight() const { return height; }
