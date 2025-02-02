#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject {
protected:
    float x, y;
    float width, height;

public:
    GameObject(float x, float y, float width, float height);

    virtual ~GameObject() = default;

    virtual void draw() = 0;

    float getX() const;

    float getY() const;

    float getWidth() const;

    float getHeight() const;
};

#endif
