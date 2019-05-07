//
// Created by Kory slaby on 2019-04-22.
//

#include <glad/glad.h>
#include "CarCab.h"

float cabVertices[432] = {
        //cube points           cube normals
        -1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,

        -0.85f,  0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f,  0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f,  0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,

        -0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.85f,  -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f,  -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f,  -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.85f,  0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f,  0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f,  0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        -1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,

        -0.85f,  -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f,  -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f,  -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,

        -0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 0.0f,  0.0f,  0.0f, -1.0f

};


CarCab::CarCab() {
    this->loadVertices();
}

void CarCab::loadVertices() {
    glGenVertexArrays(1, &CVAO);
    glGenBuffers(1, &CVBO);

    glBindVertexArray(CVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cabVertices), cabVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void CarCab::bindVertices() {
    glBindVertexArray(CVAO);
}
