#include "Coin.h"
#include <iostream>
#include <GLFW/glfw3.h>

Coin::Coin(float x, float y, GLuint shaderProgram)
    : GameObject(x, y, 0.03f, 0.03f), shaderProgram(shaderProgram), lifetime(500), collected(false) {
    spawnTime = glfwGetTime();  // **Coin'in oluşturulduğu zamanı al**

    // **Coin rengi: Sarı**
    color[0] = 1.0f;  // **R**
    color[1] = 1.0f;  // **G**
    color[2] = 0.0f;  // **B**
}

void Coin::update() {
    if (lifetime > 0) lifetime--;  // **Coin belirli bir süre sonra kaybolacak**
}

void Coin::draw() {
    if (collected || isExpired()) return;  // **Eğer coin toplandıysa veya süresi bittiyse çizme**

    glUseProgram(shaderProgram);

    GLint colorLocation = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform3f(colorLocation, color[0], color[1], color[2]);

    const int segments = 20;  // **Dairenin ne kadar pürüzsüz olacağı**
    float circleVertices[segments * 2];

    for (int i = 0; i < segments; i++) {
        float angle = 2.0f * 3.14159f * i / segments;
        circleVertices[i * 2] = x + width * cos(angle);
        circleVertices[i * 2 + 1] = y + height * sin(angle);
    }

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circleVertices), circleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLE_FAN, 0, segments);  // **Daireyi çiz!**

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

bool Coin::isCollected() const {
    return collected;
}

void Coin::collect() {
    collected = true;
}

bool Coin::isExpired() const {
    return (glfwGetTime() - spawnTime) > 10.0;  // **10 saniye geçti mi?**
}
