#include "../includes/functions.h"

template <typename T>
T getInput(const char *msg){
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


template int getInput<int>(const char *msg);
template double getInput<double>(const char *msg);

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
        choice = getInput<int>("");

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1:
                param1 = getInput<double>("Enter radius: ");
                shape = new Circle(param1);
                break;
            case 2:
                param1 = getInput<double>("Enter side: ");
                shape = new Square(param1);
                break;
            case 3:
                param1 = getInput<double>("Enter radius: ");
                shape = new Sphere(param1);
                break;
            case 4:
                param1 = getInput<double>("Enter side: ");
                shape = new Cube(param1);
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
                std::cin.clear();
                while (std::cin.get() != '\n' && !std::cin.eof())
                    ;
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

        while (true) {
            displayContinueMenu();
            continueChoice = getInput<int>("");

            if (continueChoice == 1 || continueChoice == 2) {
                break;
            }
            std::cout << "Invalid choice! Please enter 1 or 2.\n";
        }

        if (continueChoice == 2) {
            continueProgram = false;
        }
    }

}