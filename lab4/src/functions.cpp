#include "../includes/functions.h"


template <typename T> T getInput(const char *msg){
    T value;
    std::cout << msg;

    while (true)
    {
        if (std::cin >> value)
        {
            if (std::cin.get() == '\n')
            {
                return value;
            }
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
    }
}

void displayMenu() {
    std::cout << "\n=== Geometric Figures Menu ===\n";
    std::cout << "1. Create Circle\n";
    std::cout << "2. Create Square\n";
    std::cout << "3. Create Sphere\n";
    std::cout << "4. Create Cube\n";
    std::cout << "5. Exit Program\n";
    std::cout << "Enter your choice: ";
}

void displayContinueMenu() {
    std::cout << "\n=== What would you like to do? ===\n";
    std::cout << "1. Continue - create another figure\n";
    std::cout << "2. Exit Program\n";
    std::cout << "Enter your choice: ";
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu() {
    Shape* shape = nullptr;
    int choice;
    int continueChoice;
    double param1;
    double figureArea;
    double figureVolume;
    bool continueProgram = true;

    while (continueProgram) {
        clearScreen();
        displayMenu();
        std::cin >> choice;

        if (choice == 5) {
            break;
        }
        switch (choice) {
            case 1:
                std::cout << "Enter radius: ";
                param1 = getInput<double>("");
                shape = new Circle(param1);
                break;
            case 2:
                std::cout << "Enter side: ";
                param1 = getInput<double>("");
                shape = new Square(param1);
                break;
            case 3:
                std::cout << "Enter radius: ";
                param1 = getInput<double>("");
                shape = new Sphere(param1);
                break;
            case 4:
                std::cout << "Enter side: ";
                param1 = getInput<double>("");
                shape = new Cube(param1);
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                continue;
        }

        if (shape != nullptr) {
            clearScreen();
            std::cout << "=== Created Figure Information ===\n";
            shape->print();
            figureArea = shape->area();
            std::cout << "Area: " << figureArea << std::endl;


            if (choice == 3 || choice == 4) {
                figureVolume = shape->volume();
                std::cout << "Volume: " << figureVolume << std::endl;
            } else {
                shape->volume();
            }

            std::cout << "\nVisualization:\n";
            shape->draw();


            delete shape;
            shape = nullptr;
        }
        bool shouldBreak = false;
        if (continueChoice == 1) {
            shouldBreak = true;
        } else if (continueChoice == 2) {
            continueProgram = false;
            shouldBreak = true;
        } else {
            std::cout << "Invalid choice! Please enter 1 or 2.\n";
        }
    delete shape;

    std::cout << "\nThank you for using Geometric Figures Program!\n";
}}