#ifndef LAB4_CIRCLE_H
#define LAB4_CIRCLE_H

#include "../includes/TwoDShape.h"

class Circle: public TwoDShape{
protected:
    double radius;
public:
    explicit Circle(double circleRadius);
    void print() override;
    double area() override;
    double volume() override;
    void draw() override;
};


#endif//LAB4_CIRCLE_H
