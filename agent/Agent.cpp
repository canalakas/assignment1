#include "Agent.h"
#include <iostream>

Agent::Agent(float startX, float startY, GLuint shaderProgram)
    : GameObject(startX, startY, 0.05f, 0.05f), stepSize(0.05f), direction(1), shaderProgram(shaderProgram), score(0) {
    // **Agent rengi (Mavi tonlarında)**
    color[0] = 0.0f;
    color[1] = 0.3f;
    color[2] = 1.0f;
}

void Agent::moveUp() {
    if (y + 0.1f >= 1.0f) {  // **Ekranın en üstüne tam ulaşınca yön değiştir**
        y = 0.95f;
        direction = -1;
        std::cout << "Agent en üste ulaştı, yön değiştiriyor (Aşağı)." << std::endl;
    } else {
        y += 0.05f;
        addScore(1);
    }
}

void Agent::moveDown() {
    if (y - 0.1f <= -1.0f) {  // **Ekranın en altına tam ulaşınca yön değiştir**
        y = -0.95f;
        direction = 1;
        std::cout << "Agent en alta ulaştı, yön değiştiriyor (Yukarı)." << std::endl;
    } else {
        y -= 0.05f;
        addScore(1);
    }
}

void Agent::moveLeft() {
    x -= stepSize;
}

// **Agent'ı sağa hareket ettir**
void Agent::moveRight() {
    x += stepSize;
}

// **Agent’ın yönünü öğren**
int Agent::getDirection() const {
    return direction;
}

// **Agent’ın yönünü değiştir**
void Agent::setDirection(int newDirection) {
    direction = newDirection;
}

// **Agent'ın bir araca çarpıp çarpmadığını kontrol et**
bool Agent::checkCollision(float carX, float carY, float carWidth, float carHeight) {
    return (x < carX + carWidth && x + width > carX && y < carY + carHeight && y + height > carY);
}

void Agent::addScore(int points) {
    score += points;
}

int Agent::getScore() const {
    return score;
}

// **Agent’ı çizen fonksiyon**
void Agent::draw() {
    glUseProgram(shaderProgram);

    GLint colorLocation = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform3f(colorLocation, color[0], color[1], color[2]);

    // **Agent yönüne bağlı olarak üçgenin yönünü değiştirelim**
    float triangleVertices[] = {
        x, y + (direction * height), // **Agent yukarı bakıyorsa yukarı, aşağı bakıyorsa aşağı çizilecek**
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
