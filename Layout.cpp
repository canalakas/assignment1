#include "Layout.h"
#include <iostream>

Layout::Layout(GLuint shaderProgram) : shaderProgram(shaderProgram), VAO(0), VBO(0) {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices_size * sizeof(float)), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Layout::~Layout() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void Layout::draw() {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    glUniform1i(glGetUniformLocation(shaderProgram, "isDashed"), false);
    glDrawArrays(GL_TRIANGLES, 0, 36);

    glLineWidth(1.0f);
    glUniform1i(glGetUniformLocation(shaderProgram, "isDashed"), true);
    glDrawArrays(GL_LINES, 36, 100);

    glBindVertexArray(0);
}
