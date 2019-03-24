//
// Created by Kory slaby on 2019-02-21.
// Does the inits

#ifndef CLION_SHAPE_H
#define CLION_SHAPE_H



class Shape {
protected:
    unsigned int VBO, VAO;
    std::string currentShape;

public:
    Shape();
    Shape(std::string shape);
    void setCurrentShape(std::string shape);
    void bufferCreate(float *array, int size);
    void bindBuffer();
    void clearBuffer();
    std::string getCurrentShape();
};


#endif //CLION_SHAPE_H
