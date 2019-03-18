//
// Created by Kory slaby on 2019-02-21.
//
/*
#include <iostream>
#include "../../LearnOpenGL/includes/glad/glad.h"
#include <GLFW/glfw3.h>

#include "../../LearnOpenGL/includes/glm/glm.hpp"
#include "../../LearnOpenGL/includes/glm/gtc/matrix_transform.hpp"
#include "../../LearnOpenGL/includes/glm/gtc/type_ptr.hpp"

#include "Shape.h"
*/

 #include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "shader.h"
#include "Shape.h"
 
float cubeVertices[] = {
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,

        0.5f,  0.5f,  0.5f,  0.5, 0.0, 0.5f,
        0.5f,  0.5f, -0.5f,  0.5, 0.0, 0.5f,
        0.5f, -0.5f, -0.5f,  0.5, 0.0, 0.5f,
        0.5f, -0.5f, -0.5f,  0.5, 0.0, 0.5f,
        0.5f, -0.5f,  0.5f,  0.5, 0.0, 0.5f,
        0.5f,  0.5f,  0.5f,  0.5, 0.0, 0.5f,

        -0.5f, -0.5f, -0.5f,  0.5, 0.5, 0.0f,
        0.5f, -0.5f, -0.5f,  0.5, 0.5, 0.0f,
        0.5f, -0.5f,  0.5f,  0.5, 0.5, 0.0f,
        0.5f, -0.5f,  0.5f,  0.5, 0.5, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.5, 0.5, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.5, 0.5, 0.0f,

        -0.5f,  0.5f, -0.5f,  0.0, 0.5, 0.5f,
        0.5f,  0.5f, -0.5f,  0.0, 0.5, 0.5f,
        0.5f,  0.5f,  0.5f,  0.0, 0.5, 0.5f,
        0.5f,  0.5f,  0.5f,  0.0, 0.5, 0.5f,
        -0.5f,  0.5f,  0.5f,  0.0, 0.5, 0.5f,
        -0.5f,  0.5f, -0.5f, 0.0, 0.5, 0.5f
};

void Shape::setCurrentShape (int shape) {
    currentShape = shape;
}

void Shape::bufferCreate() {
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
    //teling opengl how to interpret the vertex data.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);

}

void Shape::bindBuffer() {
    glBindVertexArray(VAO);
}
