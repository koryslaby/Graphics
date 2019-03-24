//
// Created by Kory slaby on 2019-03-22.
//

#include "Plain.h"

float planeVertices[36] = {
        -0.5f,  0.5f, -0.5f,  1.0, 1.0, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0, 0.0, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0, 1.0, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0, 1.0, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0, 0.0, 1.0f,
        -0.5f,  0.5f, -0.5f, 1.0, 1.0, 0.0f
};

void Plain::plainBufferCreate() {
    this -> bufferCreate(planeVertices, 36);
}

void  Plain::plainBindBuffer() {
    this -> bindBuffer();
}