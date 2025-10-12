#ifndef LAB6_MENU_H
#define LAB6_MENU_H

#include "String.h"
#include <iostream>

class Menu {
public:
    static void showMenu();
    static void processString(String& str, size_t index, size_t substrStart, size_t substrLen);
    static void run();
};

#endif//LAB6_MENU_H
