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

Shape::Shape() {

}

Shape::Shape(std::string shape) {
    this ->setCurrentShape(shape);
}

void Shape::setCurrentShape(std::string shape) {
    this -> currentShape = shape;

}

void Shape::bufferCreate(float currentVertex[], int size){
    float shapeInfo[size];
    for(int i = 0; i < size; i++){
        shapeInfo[i] = currentVertex[i];
    }
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof((shapeInfo)), shapeInfo, GL_STATIC_DRAW);
    //teling opengl how to interpret the vertex data.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*) nullptr);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

}

void Shape::bindBuffer() {

    glBindVertexArray(VAO);


}

void Shape::clearBuffer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

std::string Shape::getCurrentShape() {
    return currentShape;
}


