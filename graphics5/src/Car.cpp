//
// Created by Kory slaby on 2019-04-13.
//
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "Car.h"
#include "Cube.h"

#include <iostream>
#include <cmath>
#include <glm/glm.hpp>
#include <glad/glad.h>

#include "shader.h"
#include "CarCab.h"
#include "Circle.h"

glm::vec3 wheelPos[] = {
        glm::vec3(-1, 0, -2),//0
        glm::vec3(-1, 0, 2),//1
        glm::vec3(1, 0, -2),//2
        glm::vec3(1, 0, 2)//2
};

glm::vec3 cabPos[] = {
        glm::vec3(.3, 0, 0),
        glm::vec3(1.3, 0, 0),
        glm::vec3(-.6, 0, 0),
        glm::vec3(.3, 0, -1),
        glm::vec3(.3, 0, 1),
        glm::vec3(.3, 0, 2),
        glm::vec3(.3, 0, 3),
        glm::vec3(.3, .8, 0),
        glm::vec3(.3, .8, .7)
};

float steerDirection = 1;

Car::Car(glm::vec3 pos, glm::vec3 scale, float Angle) {
    this->carPos = pos;
    this->scale = scale;
    this->carRot = Angle;
    this->carCam.Position = this->carPos;
}

void Car::renderCab(Shader shader) {
    shader.setVec3("objectColor", this->bodyCollor);
    this->upDateBody(shader);
    for (int i = 0; i < 10; ++i) {
        glm::vec3 upPos = cabPos[i];
        upPos.z -=.7;
        glm::mat4 model(1.0f);
        model = glm::translate(model, upPos);
        //model = glm::rotate(model, glm::radians(this->carRot), glm::vec3(0.0f, 1.0f, 0.0f));
        if (i==8){
            model = glm::scale(model, glm::vec3(.5,.5,.5));
        }
        if (i == 7){
            model = glm::scale(model, glm::vec3(.9,.8,.9));
        }
        shader.setMat4("model", model);
        //glDrawArrays(GL_TRIANGLES, 0, 72);//72



        this->cabCub.bindVertices();
        glDrawArrays(GL_TRIANGLES, 0, 36);
    }

}

void Car::renderTires(Shader shader, bool steerLeft, bool steerRight) {
    glm::mat4 model(1.0f);
    glm::mat4 instance = glm::mat4(1.0f);
    float steer = 0.0f;


    float  angle = 0.0f;
    if (steerLeft) {
        angle += 45.0f;
        steer = 1;
        if(drivingCar)
            this->carRot += steerDirection;
    }
    if (steerRight){
        steer = -1;
        angle += -45.0f;
        if(drivingCar)
            this->carRot -= steerDirection;
    }


    rotateCar(YAXIS, this->carRot, shader);

    for (int i = 0; i < this->numWheels; ++i) {


        this->wheel.bindVertices();
        shader.setVec3("objectColor", this->wheelCollor);
        model = glm::mat4 (1.0f);
        model = glm::translate(model, (wheelPos[i]));
        model = glm::scale(model, this->scale);
        model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));

        if(drivingCar)
        {
            float rotTire = 1.0f;
            if(i == 1 || i == 3) {
                model = glm::rotate(model, glm::radians((this->tireRPM += rotTire)), glm::vec3(steer, 0.0f, 1.0f));
            } else
                model = glm::rotate(model, glm::radians((this->tireRPM+=rotTire)), glm::vec3(0.0f, 0.0f, 1.0f));

        }

        if ( i == 1 || i == 3) {
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
        }

        shader.setMat4("model", model);
        glDrawArrays(GL_TRIANGLES, 0, 72);//72
        shader.setVec3("objectColor", this->rimCollor);

        this->wheel.bindWrap();
        glDrawArrays(GL_TRIANGLES, 0, 72);//72

    }

}

void Car::driveCar() {
    if(this->drivingCar == true){
        this->carPos.z += carVol * cos(float (this->carRot * M_PI/180));
        this->carPos.x += carVol * sin(float (this->carRot * M_PI/180));
    }
    this->drivingCar = false;
}

void Car::setPos(glm::vec3 setter) {
    this->carPos = setter;
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
    instance = glm::translate(instance, this->carPos);
    instance = glm::rotate(instance, glm::radians(this->carRot), this->carRotAxis);
    shader.setMat4("instance", instance);
    this->rotationCheck();

}

void Car::upDateBody(Shader shader){
    glm::mat4 instance = glm::mat4(1.0f);
    glm::vec3 upPos = this->carPos;
    instance = glm::translate(instance, upPos);
    instance = glm::rotate(instance, glm::radians(this->carRot), glm::vec3(0,1,0));
    shader.setMat4("instance", instance);
}

void Car::renderCar(Shader shader, bool steerLeft, bool steerRight) {
    this->renderCab(shader);
    this->renderTires(shader, steerLeft, steerRight);
    this->driveCar();
}

void Car::setDrivingCar(bool setter) {
    this->drivingCar = setter;
}

void Car::rotationCheck() {
    if(this->carRot > 360){
        this->carRot = 0;
    }
    if(this->carRot < 0){
        this->carRot = 360;
    }
}