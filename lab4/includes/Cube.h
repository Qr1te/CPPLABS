#ifndef LAB4_CUBE_H
#define LAB4_CUBE_H

#include "ThreeDShape.h"

class Cube: public ThreeDShape {
private:
    double side;
public:
    explicit Cube(double cubeSide);
    void print() override;
    double area() override;
    double volume() override;
    void draw() override;

};

#endif//LAB4_CUBE_H
