//
// Created by Kory slaby on 2019-04-13.
//

#ifndef GRAPHICS4_CIRCLE_H
#define GRAPHICS4_CIRCLE_H


#include <glm/fwd.hpp>

class Circle {
public:
    unsigned int CVBO, CVAO, WVBO, WVAO;
    Circle();
    Circle(glm::mat4 model);
    void bindVertices();
    void loadWrap();
    void bindWrap();

private:
    void loadVertices();
};


#endif //GRAPHICS4_CIRCLE_H
