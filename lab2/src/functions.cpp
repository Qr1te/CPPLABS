#include "../includes/functions.h"

void menu() {
    char reset = 'y';
    do {
        String s1;
        String s2;
        int choice;
        std::cout << "Enter a string: ";
        std::cin >> s1;
        std::cout << "What you want to do with your string: 1.add other string 2. "
                     "compare string: ";
        std::cin >> choice;
        while (choice != 1 && choice != 2) {
            std::cout << "Incorrect choice, try again" << std::endl;
            std::cin >> choice;
        }
        if (choice == 1) {
            std::cout << "Enter the second string to add: ";
            std::cin >> s2;
            s1 += s2;
            std::cout << "Your new string: " << s1 << std::endl;
            std::cout << "Want to try again?(y/n)" << std::endl;
            std::cin >> reset;
            system("cls");
        } else if (choice == 2) {
            std::cout << "Enter the second string to compare: ";
            std::cin >> s2;
            if (s1 == s2) {
                std::cout << "Strings are equal" << std::endl;
            } else {
                std::cout << "String are not equal" << std::endl;
            }
            std::cout << "Want to try again?(y/n)" << std::endl;
            std::cin >> reset;
            system("cls");
        }

    } while (reset != 'n');
}