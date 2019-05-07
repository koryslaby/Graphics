//
// Created by Kory slaby on 2019-04-13.
//

#ifndef GRAPHICS4_CAR_H
#define GRAPHICS4_CAR_H


#include <glm/glm.hpp>
#include "shader.h"
#include "Circle.h"
#include "CarCab.h"
#include "Cube.h"
#include "camera.h"

enum axis {
    XAXIS,
    YAXIS,
    ZAXIS
};

class Car {
private:
    void rotationCheck();
    void renderTires(Shader shader, bool, bool);
    void renderCab(Shader shader);
public:
    static const int numWheels = 4;
    bool drivingCar = false;
    bool firstRender = true;
    float carVol = .09;
    float tireRPM = 1;
    Camera carCam;
    glm::vec3 carPos;
    glm::vec3 scale;
    glm::vec3 wheelCollor = glm::vec3(1.0f, 0.5f, 0.31f);
    glm::vec3 rimCollor = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 bodyCollor = glm::vec3(1.0f, 0.0f, 0.0f);

    float carRot;
    float carTurnSpeed = 1;
    glm::vec3 carRotAxis;
    Circle wheel;
    CarCab cab;
    Cube cabCub;

    Car(glm::vec3, glm::vec3 scale, float angle);

    void upDateBody(Shader);
    void renderCar(Shader, bool, bool);
    void rotateCar(axis , float, Shader);
    void driveCar();
    void setPos(glm::vec3);
    void setDrivingCar(bool);
    void turnCar(bool, bool, Shader);
    void drive();
};



#endif //GRAPHICS4_CAR_H
