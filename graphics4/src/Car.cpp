//
// Created by Kory slaby on 2019-04-13.
//

#include "Car.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glad/glad.h>
#include "shader.h"
#include "Circle.h"

glm::vec3 wheelPos[] = {
        glm::vec3(-2, 0, 0),
        glm::vec3(-2, 0, 1),
        glm::vec3(2, 0, -1),
        glm::vec3(2, 0, 1)
};

float steerDirection = 1;

Car::Car(glm::vec3 pos, glm::vec3 scale, float Angle) {
    this->carPos = pos;
    this->scale = scale;
    this->carRot = Angle;
}

void Car::renderTires(Shader shader, bool steerLeft, bool steerRight) {
    glm::mat4 model(1.0f);
    std::cout << "steering direction is: " << steerDirection << std::endl;

    float  angle = 0.0f;
    if (steerLeft) {
        angle = 45.0f;
        this->carRot += steerDirection;
    }
    if (steerRight){
        angle = -45.0f;
        this->carRot -= steerDirection;
    }
    rotateCar(YAXIS, this->carRot, shader);
    for (int i = 0; i < this->numWheels; ++i) {

        this->wheel.bindVertices();
        shader.setVec3("objectColor", this->wheelCollor);
        model = glm::mat4 (1.0f);
        model = glm::translate(model, (this->carPos + wheelPos[i]));
        model = glm::scale(model, this->scale);
        if ( i >= 2) {
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        }
        shader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 72);//72
        shader.setVec3("objectColor", this->rimCollor);

        this->wheel.bindWrap();
        glDrawArrays(GL_TRIANGLES, 0, 72);//72

    }
}



void Car::rotateCar(axis a, float angle, Shader shader) {
    glm::mat4 instance = glm::mat4(1.0f);
    if(a == XAXIS){
        this->carRotAxis = glm::vec3(1,0,0);
    }
    if(a == YAXIS){
        this->carRotAxis = glm::vec3(0,1,0);
    }
    if(a == XAXIS){
        this->carRotAxis = glm::vec3(0,0,1);
    }
    this->carRot = angle;
    instance = glm::rotate(instance, glm::radians(this->carRot), this->carRotAxis);
    shader.setMat4("instance", instance);

}