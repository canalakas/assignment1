#include "Car.h"
#include <GL/glew.h>

Car::Car(float x, float y, float speed, bool direction, GLuint shaderProgram)
    : Vehicle(x, y, speed, 0.1f, 0.05f, direction, shaderProgram) {}

void Car::draw() {
    glUseProgram(shaderProgram);

    GLint colorLocation = glGetUniformLocation(shaderProgram, "objectColor");
    glUniform3f(colorLocation, color[0], color[1], color[2]);

    float carVertices[] = {
        x, y,
        x + width, y,
        x + width, y - height,

        x, y,
        x + width, y - height,
        x, y - height
    };

    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(carVertices), carVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glDrawArrays(GL_TRIANGLES, 0, 6);

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}
