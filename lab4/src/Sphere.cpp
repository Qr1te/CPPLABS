#include "../includes/Sphere.h"

Sphere::Sphere(double sphereRadius): radius(sphereRadius) {}

void Sphere::print() {
    std::cout << "Type: Sphere(3D figure)" <<std::endl;
    std::cout << "Radius: " << radius << std::endl;
}

double Sphere::area() {
    return 4 * 3.141592 * radius * radius;
}

double Sphere::volume() {
    return 4 * 3.141592 * radius * radius * radius/3;
}

void Sphere::draw() {
    std::cout <<"";
}