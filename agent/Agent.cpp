#include "Agent.h"
#include <iostream>

Agent::Agent(float startX, float startY, GLuint shaderProgram)
    : GameObject(startX, startY, 0.05f, 0.05f), stepSize(0.05f), direction(1), shaderProgram(shaderProgram), score(0) {
    // Blue Agent
    color[0] = 0.0f;
    color[1] = 0.3f;
    color[2] = 1.0f;
}

void Agent::moveUp() {
    if (y + 0.1f >= 1.0f) {  // Change direction at the top of the frame
        y = 0.95f;
        direction = -1;
        std::cout << "Agent en üste ulaştı, yön değiştiriyor (Aşağı)." << std::endl;
    } else {
        y += 0.05f;
        addScore(1);
    }
}

void Agent::moveDown() {
    if (y - 0.1f <= -1.0f) {  // Change direction at the bottom of the frame
        y = -0.95f;
        direction = 1;
        std::cout << "Agent en alta ulaştı, yön değiştiriyor (Yukarı)." << std::endl;
    } else {
        y -= 0.05f;
        addScore(1);
    }
}

// Move agent to left
void Agent::moveLeft() {
    x -= stepSize;
}

// Move agent to right
void Agent::moveRight() {
    x += stepSize;
}

// get Agent direction
int Agent::getDirection() const {
    return direction;
}

void Agent::setDirection(int newDirection) {
    direction = newDirection;
}

// Check collision between agent and vehicles
bool Agent::checkCollision(float carX, float carY, float carWidth, float carHeight) {
    return (x < carX + carWidth && x + width > carX && y < carY + carHeight && y + height > carY);
}

void Agent::addScore(int points) {
    score += points;
}

int Agent::getScore() const {
    return score;
}

void Agent::draw() {
    glUseProgram(shaderProgram);

    GLint colorLocation = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform3f(colorLocation, color[0], color[1], color[2]);

    float triangleVertices[] = {
        x, y + (direction * height),
        x - width, y - (direction * height),
        x + width, y - (direction * height)
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
