#include "../includes/Cube.h"

Cube::Cube(double cubeSide): side(cubeSide){}

void Cube::print() {
    std::cout << "Type: Cube(3D figure)" <<std::endl;
    std::cout << "Side: " << side << std::endl;
}

double Cube::area() {
    return 4 * side * side;
}

double Cube::volume() {
    return side * side * side;
}

void Cube::draw() {
    std::cout << "   +-------+   " << std::endl;
    std::cout << "  /|      /|   " << std::endl;
    std::cout << " +-------+ |   " << std::endl;
    std::cout << " | |     | |   " << std::endl;
    std::cout << " | +-----|-+   " << std::endl;
    std::cout << " |/      |/    " << std::endl;
    std::cout << " +-------+     " << std::endl;
}
