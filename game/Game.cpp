#include "Game.h"
#include <cstdlib>
#include <iostream>
#include <GLFW/glfw3.h>

#include "coin/Coin.h"

Game::Game(GLuint vehicleShaderProgram, GLuint agentShaderProgram, GLuint coinShaderProgram)
    : vehicleShaderProgram(vehicleShaderProgram), agentShaderProgram(agentShaderProgram),
      coinShaderProgram(coinShaderProgram) {
    agent = new Agent(0.0f, -0.95f, agentShaderProgram); // **Başlangıç noktası alt kaldırım**
    startTime = glfwGetTime();
}

Game::~Game() {
    for (auto v: vehicles) delete v;
    for (auto c: coins) delete c;
    delete agent;
}

void Game::update() {
    if (isPaused && !isStepMode) return;

    // **Araçları güncelle ve bellekten sil**
    for (auto it = vehicles.begin(); it != vehicles.end();) {
        (*it)->update();
        if ((*it)->isOutOfBounds()) {
            delete *it;
            it = vehicles.erase(it);
        } else {
            ++it;
        }
    }

    // **Çarpışma kontrolü**
    for (auto v: vehicles) {
        if (agent->checkCollision(v->getX(), v->getY(), v->getWidth(), v->getHeight())) {
            std::cout << "ÇARPIŞMA! Oyun Bitti.\n";
            exit(0);
        }
    }

    // **Coin'leri güncelle ve 10 saniyeyi aşanları temizle**
    for (auto it = coins.begin(); it != coins.end();) {
        if ((*it)->isExpired()) {
            delete *it;
            it = coins.erase(it);
            std::cout << "Coin süresi doldu ve silindi.\n";
        } else {
            ++it;
        }
    }

    // **Coin'leri kontrol et ve toplananları sil**
    for (auto it = coins.begin(); it != coins.end();) {
        if (!(*it)->isCollected() && agent->checkCollision((*it)->getX(), (*it)->getY(), (*it)->getWidth(), (*it)->getHeight())) {
            (*it)->collect();
            agent->addScore(5);
            std::cout << "Skor: " << agent->getScore() << "\n";

            delete *it;  // **Coin objesini bellekten sil**
            it = coins.erase(it);  // **coins vektöründen çıkart**
        } else {
            ++it;
        }
    }
    checkWinCondition();

    if (isStepMode) {
        std::cout << "Tek adım ilerletildi. Mevcut skor: " << agent->getScore() << std::endl;
        std::cout << "Agent Konumu: X: " << agent->getX() << " Y: " << agent->getY() << std::endl;

        for (auto v : vehicles) {
            std::cout << "Araç Konumu: X: " << v->getX() << " Y: " << v->getY() << std::endl;
        }
        for (auto c : coins) {
            std::cout << "Coin Konumu: X: " << c->getX() << " Y: " << c->getY() << std::endl;
        }
        isStepMode = false;
    }
}


void Game::draw() {
    for (auto v: vehicles) v->draw();
    for (auto c: coins) c->draw();
    agent->draw();
}

void Game::spawnVehicle() {
    if (isPaused) return;  // **Eğer oyun duraklatıldıysa yeni araç spawn etme**

    float laneCenters[] = {0.75f, 0.43f, 0.03f, -0.37f, -0.77f};  // **Şeritlerin merkezleri 0.01 aşağı kaydırıldı**

    int lane = rand() % 5;
    float xPos = (rand() % 2) ? -1.1f : 1.1f;
    bool movingRight = (xPos < 0);

    if (rand() % 2) {
        vehicles.push_back(new Car(xPos, laneCenters[lane], 0.01f, movingRight, vehicleShaderProgram));
    } else {
        vehicles.push_back(new Truck(xPos, laneCenters[lane], 0.007f, movingRight, vehicleShaderProgram));
    }

    std::cout << "Yeni Araç Spawn: X: " << xPos << " Y: " << laneCenters[lane] << std::endl;
}



void Game::handleInput(int key) {
    if (key == GLFW_KEY_P) {
        togglePause();
    } else if (key == GLFW_KEY_S) {
        step();
    } else if (key == GLFW_KEY_Q) {
        std::cout << "Oyun kapatılıyor. Toplam Skor: " << agent->getScore() << std::endl;
        exit(0);
    } else if (!isPaused) {
        // **Eğer oyun duraklatılmadıysa agent hareket etsin**
        if (key == GLFW_KEY_UP && agent->getDirection() == 1) {
            agent->moveUp();
        } else if (key == GLFW_KEY_DOWN && agent->getDirection() == -1) {
            agent->moveDown();
        } else if (key == GLFW_KEY_LEFT) {
            agent->moveLeft();
        } else if (key == GLFW_KEY_RIGHT) {
            agent->moveRight();
        } else {
            std::cout << "HATA: Yanlış yöne hareket ettin! Oyun bitti.\n";
            exit(0);
        }
    }
}

void Game::spawnCoin() {
    if (isPaused) return;  // **Eğer oyun duraklatıldıysa yeni coin spawn etme**

    if (rand() % 10 < 2) {
        float lanePositions[] = {0.76f, 0.44f, 0.04f, -0.36f, -0.76f};
        int lane = rand() % 5;
        float xPos = (rand() % 2) ? -0.5f : 0.5f;

        bool duplicate = false;
        for (auto c : coins) {
            if (c->getX() == xPos && c->getY() == lanePositions[lane]) {
                duplicate = true;
                break;
            }
        }

        if (!duplicate) {
            coins.push_back(new Coin(xPos, lanePositions[lane], coinShaderProgram));
            std::cout << "Yeni coin spawn edildi: X: " << xPos << " Y: " << lanePositions[lane] << std::endl;
        }
    }
}



void Game::addScore(int points) {
    score += points;
}

int Game::getScore() const {
    return score;
}

void Game::togglePause() {
    isPaused = !isPaused;
    std::cout << (isPaused ? "Oyun duraklatıldı." : "Oyun devam ediyor.") << std::endl;
}

void Game::step() {
    if (!isPaused) {
        isPaused = true; // **Eğer oyun çalışıyorsa önce duraklat**
    }
    isStepMode = true;
}

void Game::checkWinCondition() {
    double elapsedTime = glfwGetTime() - startTime;  // **Geçen süreyi hesapla**

    if (agent->getScore() >= 50) {
        std::cout << "🏆 Tebrikler! 50 Skora Ulaştınız! Oyunu Kazandınız! 🏆" << std::endl;
        exit(0);
    }

    if (elapsedTime >= 60.0) {
        std::cout << "⏳ 1 Dakika Hayatta Kaldınız! Oyunu Kazandınız! 🏆" << std::endl;
        exit(0);
    }
}