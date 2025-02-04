#ifndef LAYOUT_H
#define LAYOUT_H

#include "vertices.h"
#include <GL/glew.h>

class Layout {
private:
    GLuint VAO, VBO;
    GLuint shaderProgram;

public:
    Layout(GLuint shaderProgram);
    ~Layout();
    void draw();
};

#endif
