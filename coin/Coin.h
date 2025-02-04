#ifndef COIN_H
#define COIN_H

#include "GameObject.h"
#include <GL/glew.h>

class Coin : public GameObject {
private:
    GLuint shaderProgram;
    float color[3];
    int lifetime;
    bool collected;
    double spawnTime;

public:
    Coin(float x, float y, GLuint shaderProgram);
    void update();
    void draw() override;
    bool isCollected() const;
    void collect();
    bool isExpired() const;
};

#endif
