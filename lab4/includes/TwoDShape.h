#ifndef LAB4_TWODSHAPE_H
#define LAB4_TWODSHAPE_H

#include "Shape.h"

class TwoDShape: public Shape {
public:
    void print() override = 0;
    double area() override = 0;
    double volume() override = 0;
    void draw() override = 0;


};

#endif//LAB4_TWODSHAPE_H
