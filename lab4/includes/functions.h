#ifndef LAB4_FUNCTIONS_H
#define LAB4_FUNCTIONS_H

#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Sphere.h"
#include "Cube.h"

void displayMenu();
void clearScreen();
template <typename T> T getInput(const char *msg);
void displayContinueMenu();
void menu();

#endif//LAB4_FUNCTIONS_H
