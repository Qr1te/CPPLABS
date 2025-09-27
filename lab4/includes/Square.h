#ifndef LAB4_SQUARE_H
#define LAB4_SQUARE_H

#include "../includes/TwoDShape.h"

class Square: public TwoDShape{
protected:
    double side;
public:
    Square(double squareSide);
    void print() override;
    double area() override;
    double volume() override;
    void draw() override;
};


#endif//LAB4_SQUARE_H
