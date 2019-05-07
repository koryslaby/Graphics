//
// Created by kory on 3/20/19.
//

#ifndef GRAPHICS3_2_CUBE_H
#define GRAPHICS3_2_CUBE_H


#include "shader.h"

class Cube {
public:
    static int numCubes;
    unsigned int CVBO, CVAO;
    glm::vec3 position;
    glm::vec3 objectColor;
    glm::vec3 lightColor;
    glm::vec3 lightPos;
    glm::mat4 objectModel;
    Cube();
    Cube(glm::mat4 model);
    void bindVertices();

private:
    void loadVertices();
};


#endif //GRAPHICS3_2_CUBE_H
