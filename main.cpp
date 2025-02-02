#include "shaders/ShaderLoader.h"
#include "Layout.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Game.h"

GLuint shaderProgram;
Layout *layout;
Game *game;
GLFWwindow *window;
double lastSpawnTime = 0.0;

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    layout->draw();
    game->draw();

    glfwSwapBuffers(window);
}

void update() {
    game->update();

    // **Araçları belirli aralıklarla ekrana ekleyelim**
    double currentTime = glfwGetTime(); // **Geçen zamanı al**
    if (currentTime - lastSpawnTime >= 1.5) {
        // **1.5 saniyede bir araç üret**
        game->spawnVehicle();
        game->spawnCoin();
        lastSpawnTime = currentTime;
    }

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        game->handleInput(key);
    }
}

void init() {
    glewExperimental = GL_TRUE;
    glewInit();

    GLuint shaderProgram = ShaderLoader::LoadShaders("/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/vertex_shader.vs", "/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/fragment_shader.fs");
    GLuint vehicleShaderProgram = ShaderLoader::LoadShaders("/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/vehicle_shader.vs", "/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/vehicle_shader.fs");
    GLuint agentShaderProgram = ShaderLoader::LoadShaders("/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/agent_shader.vs", "/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/agent_shader.fs");
    GLuint coinShaderProgram = ShaderLoader::LoadShaders("/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/coin_shader.vs", "/Users/canalakas/Desktop/tobb/Spring 2025/BIL 539 Bilgisayar Grafikleri/Assignment 1/assignment/shaders/coin_shader.fs");

    glUseProgram(shaderProgram);
    layout = new Layout(shaderProgram);
    game = new Game(vehicleShaderProgram, agentShaderProgram, coinShaderProgram);
}

int main() {
    if (!glfwInit()) {
        std::cerr << "GLFW başlatılamadı!" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(500, 600, "OpenGL with GLFW", nullptr, nullptr);
    if (!window) {
        std::cerr << "GLFW pencere oluşturulamadı!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    init();

    while (!glfwWindowShouldClose(window)) {
        glfwSetKeyCallback(window, keyCallback);
        display();
        update();
        glfwPollEvents();
    }

    delete layout;
    delete game;
    glfwTerminate();
    return 0;
}
