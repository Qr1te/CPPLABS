#include "../includes/Square.h"

Square::Square(double squareSide):side(squareSide){}

void Square::print() {
    std::cout << "Type: Square(2D figure)" <<std::endl;
    std::cout << "Side: " << side << std::endl;
}

double Square::area() {
    return side * side;
}

double Square::volume() {
    std::cout << "There is no volume for 2D shape figures"  <<std::endl;
    return 0;
}

void Square::draw() {
    std::cout <<"";
}