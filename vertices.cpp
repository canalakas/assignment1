//
// Created by Can Alakaş on 27.01.2025.
//
#include "vertices.h"
#include <cstddef> // size_t türü için gerekli

float vertices[] = {
    // Birinci dikdörtgen
    -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.92f,
    -1.0f, 1.0f, 1.0f, 0.92f, -1.0f, 0.92f,

    // İkinci dikdörtgen
    -1.0f, 0.68f, 1.0f, 0.68f, 1.0f, 0.6f,
    -1.0f, 0.68f, 1.0f, 0.6f, -1.0f, 0.6f,

    // Üçüncü dikdörtgen
    -1.0f, 0.28f, 1.0f, 0.28f, 1.0f, 0.2f,
    -1.0f, 0.28f, 1.0f, 0.2f, -1.0f, 0.2f,

    // Dördüncü dikdörtgen
    -1.0f, -0.12f, 1.0f, -0.12f, 1.0f, -0.2f,
    -1.0f, -0.12f, 1.0f, -0.2f, -1.0f, -0.2f,

    // Beşinci dikdörtgen
    -1.0f, -0.52f, 1.0f, -0.52f, 1.0f, -0.6f,
    -1.0f, -0.52f, 1.0f, -0.6f, -1.0f, -0.6f,

    // Altıncı dikdörtgen
    -1.0f, -0.92f, 1.0f, -0.92, 1.0f, -1.0f,
    -1.0f, -0.92f, 1.0f, -1.0f, -1.0f, -1.0f,

    // Birinci yol
    -1.0f, 0.84f, 1.0f, 0.84f,
    -1.0f, 0.76f, 1.0f, 0.76f,

    //İkinci Yol
    -1.0f, 0.52f, 1.0f, 0.52f,
    -1.0f, 0.44f, 1.0f, 0.44f,
    -1.0f, 0.36f, 1.0f, 0.36f,

    //Üçüncü Yol
    -1.0f, 0.12f, 1.0f, 0.12f,
    -1.0f, 0.04f, 1.0f, 0.04f,
    -1.0f, -0.04f, 1.0f, -0.04f,

    //Dördüncü Yol
    -1.0f, -0.28f, 1.0f, -0.28f,
    -1.0f, -0.36f, 1.0f, -0.36f,
    -1.0f, -0.44f, 1.0f, -0.44f,

    //Beşinci Yol
    -1.0f, -0.68f, 1.0f, -0.68f,
    -1.0f, -0.76f, 1.0f, -0.76f,
    -1.0f, -0.84f, 1.0f, -0.84f,

};

// Eleman sayısını tanımla
const size_t vertices_size = sizeof(vertices) / sizeof(vertices[0]);
