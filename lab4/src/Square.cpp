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
    std::cout << "Drawing a square " << side << "x" << side << std::endl;
    auto w_int = static_cast<int>(side);
    auto h_int = static_cast<int>(side);

    for (int i = 0; i < h_int; i++) {
        for (int j = 0; j < w_int; j++) {
            if (i == 0 || i == h_int-1 || j == 0 || j == w_int-1)
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
}
