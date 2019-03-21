//
// Created by kory on 3/20/19.
//

#ifndef GRAPHICS3_2_CUBE_H
#define GRAPHICS3_2_CUBE_H


#include "Shape.h"

class Cube: public Shape {
public:
    Cube(): Shape(){};
    Cube(std::string shape): Shape(shape){};
    void cubeBufferCreate();

};


#endif //GRAPHICS3_2_CUBE_H
