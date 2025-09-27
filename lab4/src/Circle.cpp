#include "../includes/Circle.h"

Circle::Circle(double circleRadius): radius(circleRadius) {}

void Circle::print() {
    std::cout << "Type: Circle(2D figure)" <<std::endl;
    std::cout << "Radius: " << radius << std::endl;
}

double Circle::area() {
    return 3.141592 * radius * radius;
}

double Circle::volume() {
    std::cout << "There is no volume for 2D shape figures"  <<std::endl;
    return 0;
}

void Circle::draw() {
    std::cout <<"";
}

