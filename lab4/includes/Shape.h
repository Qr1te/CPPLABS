#ifndef LAB4_SHAPE_H
#define LAB4_SHAPE_H

#include <iostream>

class Shape {
public:
    virtual void print() = 0;
    virtual double volume() = 0;
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~Shape();
};


#endif//LAB4_SHAPE_H
