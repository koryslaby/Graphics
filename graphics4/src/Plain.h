//
// Created by Kory slaby on 2019-03-22.
//

#ifndef GRAPHICS3_2_PLAIN_H
#define GRAPHICS3_2_PLAIN_H

#include <iostream>

class Plain {
public:
    static int numCubes;
    unsigned int CVBO, CVAO;
    glm::vec3 position;
    glm::vec3 objectColor;
    glm::vec3 lightColor;
    glm::vec3 lightPos;
    glm::mat4 objectModel;
    Plain();
    void bindVertices();

private:
    void loadVertices();

};


#endif //GRAPHICS3_2_PLAIN_H
