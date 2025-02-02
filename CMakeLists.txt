cmake_minimum_required(VERSION 3.16)
project(assignment)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_SOURCE_DIR}/shaders
        ${PROJECT_SOURCE_DIR}/vehicle
        ${PROJECT_SOURCE_DIR}/agent
        ${PROJECT_SOURCE_DIR}/game
        ${PROJECT_SOURCE_DIR}/coin
)
# Shader dizinini tanımlayalım
add_definitions(-DSHADER_DIR="${PROJECT_SOURCE_DIR}/shaders")

link_directories(/opt/homebrew/lib)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(assignment
        main.cpp
        vertices.h
        vertices.cpp
        Layout.h
        Layout.cpp
        game/Game.h
        game/Game.cpp
        vehicle/Vehicle.h
        vehicle/Vehicle.cpp
        vehicle/Car.h
        vehicle/Car.cpp
        vehicle/Truck.h
        vehicle/Truck.cpp
        shaders/ShaderLoader.h
        shaders/ShaderLoader.cpp
        agent/Agent.h
        game/GameObject.h
        game/GameObject.cpp
        agent/Agent.cpp
        coin/Coin.h
        coin/Coin.cpp)

target_link_libraries(assignment OpenGL::GL glfw GLEW)
