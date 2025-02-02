#ifndef SHADER_LOADER_H
#define SHADER_LOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>

class ShaderLoader {
public:
    static GLuint LoadShaders(const char* vertexPath, const char* fragmentPath);
};

#endif // SHADER_LOADER_H
