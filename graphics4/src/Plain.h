//
// Created by Kory slaby on 2019-03-22.
//

#ifndef GRAPHICS3_2_PLAIN_H
#define GRAPHICS3_2_PLAIN_H

#include <iostream>

#include "Shape.h"

class Plain: public Shape {
public:
    Plain(): Shape(){};
    Plain(std::string shape): Shape(shape){};
    void plainBufferCreate();
    void plainBindBuffer();

};


#endif //GRAPHICS3_2_PLAIN_H
