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
    std::cout << "Sphere with radius " << radius << ":\n";

    for (int y = -radius; y <= radius; y++) {
        for (int x = -radius; x <= radius; x++) {
            float distance = std::sqrt(x*x + y*y);

            if (distance < radius - 1) {
                std::cout << "* ";
            } else if (distance < radius + 0.5) {
                std::cout << "@ ";
            } else {
                std::cout << "  ";
            }
        }
        std:: cout << std::endl;
    }
    std::cout << std::endl;
}