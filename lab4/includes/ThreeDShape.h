#ifndef LAB4_THREEDSHAPE_H
#define LAB4_THREEDSHAPE_H

#include "../includes/Shape.h"

class ThreeDShape: public Shape{
public:
    void print() override = 0;
    double area() override = 0;
    double volume() override = 0;
    void draw() override= 0;
};


#endif//LAB4_THREEDSHAPE_H
