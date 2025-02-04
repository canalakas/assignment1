#include "vertices.h"
#include <cstddef>

float vertices[] = {
    // First rectangle
    -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.92f,
    -1.0f, 1.0f, 1.0f, 0.92f, -1.0f, 0.92f,

    // Second rectangle
    -1.0f, 0.68f, 1.0f, 0.68f, 1.0f, 0.6f,
    -1.0f, 0.68f, 1.0f, 0.6f, -1.0f, 0.6f,

    // Third rectangle
    -1.0f, 0.28f, 1.0f, 0.28f, 1.0f, 0.2f,
    -1.0f, 0.28f, 1.0f, 0.2f, -1.0f, 0.2f,

    // Fourth rectangle
    -1.0f, -0.12f, 1.0f, -0.12f, 1.0f, -0.2f,
    -1.0f, -0.12f, 1.0f, -0.2f, -1.0f, -0.2f,

    // Fifth rectangle
    -1.0f, -0.52f, 1.0f, -0.52f, 1.0f, -0.6f,
    -1.0f, -0.52f, 1.0f, -0.6f, -1.0f, -0.6f,

    // Sixth rectangle
    -1.0f, -0.92f, 1.0f, -0.92, 1.0f, -1.0f,
    -1.0f, -0.92f, 1.0f, -1.0f, -1.0f, -1.0f,

    // First road
    -1.0f, 0.84f, 1.0f, 0.84f,
    -1.0f, 0.76f, 1.0f, 0.76f,

    // Second road
    -1.0f, 0.52f, 1.0f, 0.52f,
    -1.0f, 0.44f, 1.0f, 0.44f,
    -1.0f, 0.36f, 1.0f, 0.36f,

    // THird road
    -1.0f, 0.12f, 1.0f, 0.12f,
    -1.0f, 0.04f, 1.0f, 0.04f,
    -1.0f, -0.04f, 1.0f, -0.04f,

    // Fourth road
    -1.0f, -0.28f, 1.0f, -0.28f,
    -1.0f, -0.36f, 1.0f, -0.36f,
    -1.0f, -0.44f, 1.0f, -0.44f,

    // Fifth road
    -1.0f, -0.68f, 1.0f, -0.68f,
    -1.0f, -0.76f, 1.0f, -0.76f,
    -1.0f, -0.84f, 1.0f, -0.84f,

};

const size_t vertices_size = sizeof(vertices) / sizeof(vertices[0]);
