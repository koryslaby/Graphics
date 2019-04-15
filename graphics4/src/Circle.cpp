//
// Created by Kory slaby on 2019-04-13.
//

#include <glad/glad.h>
#include "Circle.h"

float circleVertices[432] = {
        //cube points           cube normals

        //top half
        -1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.0f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        //bottom half
        1.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        0.0f,  -1.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 0.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, -0.0f, 0.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 0.0f,  0.0f,  0.0f, -1.0f,

        //top half
        -1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,

        0.0f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, 0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,


        //bottom half
        1.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,

        0.0f,  -1.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.45f,  -0.85f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        -0.85f, -0.45f, 1.0f,  0.0f,  0.0f, -1.0f,
        -1.0f, -0.0f, 1.0f,  0.0f,  0.0f, -1.0f,
        0.0f, 0.0f, 1.0f,  0.0f,  0.0f, -1.0f

};

float wrapVertices[432] = {
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


Circle::Circle() {
    this->loadVertices();
    this->loadWrap();
}

void Circle::loadVertices() {
    glGenVertexArrays(1, &CVAO);
    glGenBuffers(1, &CVBO);

    glBindVertexArray(CVAO);

    glBindBuffer(GL_ARRAY_BUFFER, CVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circleVertices), circleVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Circle::loadWrap() {
    glGenVertexArrays(1, &WVAO);
    glGenBuffers(1, &WVBO);

    glBindVertexArray(WVAO);

    glBindBuffer(GL_ARRAY_BUFFER, WVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(wrapVertices), wrapVertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

void Circle::bindVertices() {
    glBindVertexArray(CVAO);
}

void Circle::bindWrap() {
    glBindVertexArray(WVAO);
}
