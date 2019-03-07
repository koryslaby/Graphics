//
// Created by Kory slaby on 2019-02-21.
// Does the inits

#ifndef CLION_SHAPE_H
#define CLION_SHAPE_H


class Shape {
    int currentShape;
    unsigned int VBO, VAO;
public:
    void setCurrentShape(int currentShape);
    void bufferCreate();
    void bindBuffer();

private:
};


#endif //CLION_SHAPE_H
