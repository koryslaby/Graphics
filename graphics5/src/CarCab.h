//
// Created by Kory slaby on 2019-04-22.
//

#ifndef GRAPHICS4_CARCAB_H
#define GRAPHICS4_CARCAB_H


#include <glm/fwd.hpp>


class CarCab {
public:
    unsigned int CVBO, CVAO;
    CarCab();
    CarCab(glm::mat4 model);
    void bindVertices();
    void loadWrap();
    void bindWrap();

private:
    void loadVertices();

};


#endif //GRAPHICS4_CARCAB_H
