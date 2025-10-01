#ifndef LAB4_SPHERE_H
#define LAB4_SPHERE_H

#include "ThreeDShape.h"
#include <vector>
#include <cmath>

class Sphere: public ThreeDShape {
private:
    double radius;
public:
    explicit Sphere(double sphereRadius);
    void print() override;
    double area() override;
    double volume() override;
    void draw() override;


};

#endif//LAB4_SPHERE_H
