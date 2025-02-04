//
// Created by Can Alakaş on 27.01.2025.
//
#ifndef GAME_H
#define GAME_H

#include "Car.h"
#include "Truck.h"
#include "Agent.h"
#include <vector>

#include "coin/Coin.h"

class Game {
private:
    std::vector<Vehicle*> vehicles;
    std::vector<Coin*> coins;
    Agent* agent;
    GLuint vehicleShaderProgram;
    GLuint agentShaderProgram;
    GLuint coinShaderProgram;
    int score;
    bool isPaused;
    bool isStepMode;
    double startTime;

public:
    Game(GLuint vehicleShaderProgram, GLuint agentShaderProgram, GLuint coinShaderProgram);
    ~Game();

    void update();
    void draw();
    void spawnVehicle();
    void spawnCoin();
    void handleInput(int key);
    void addScore(int score);
    int getScore() const;
    void togglePause();
    void step();
    void checkWinCondition();
};

#endif
