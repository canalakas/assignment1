#ifndef AGENT_H
#define AGENT_H

#include <GL/glew.h>
#include "game/GameObject.h"

class Agent : public GameObject {
private:
    float stepSize;
    int direction;
    GLuint shaderProgram;
    float color[3];
    int score;

public:
    Agent(float startX, float startY, GLuint shaderProgram);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void draw() override;
    bool checkCollision(float carX, float carY, float carWidth, float carHeight);
    int getScore() const;
    void addScore(int points);
    int getDirection() const;
    void setDirection(int newDirection);
};

#endif
