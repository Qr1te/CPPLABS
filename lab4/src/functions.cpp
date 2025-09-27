#include "../includes/functions.h"

void displayMenu() {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add Circle\n";
    std::cout << "2. Add Square\n";
    std::cout << "3. Add Sphere\n";
    std::cout << "4. Add Cube\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter choice: ";
}

void menu(){
    Shape* shapes = nullptr;
    int choice;
    double param1;
    double figureArea;
    double figureVolume;

    while (true) {
        displayMenu();
        std::cin >> choice;
        if (choice == 5) break;
        delete shapes;
        shapes = nullptr;
        switch (choice) {
            case 1:
                std::cout << "Enter radius: ";
                std::cin >> param1;
                shapes = new Circle(param1);
                shapes->print();
                figureArea = shapes->area();
                std::cout << "Area: " << figureArea << std::endl;
                shapes->volume();
                break;
            case 2:
                std::cout << "Enter side: ";
                std::cin >> param1;
                shapes = new Square(param1);
                shapes->print();
                figureArea = shapes->area();
                std::cout << "Area: " << figureArea << std::endl;
                shapes->volume();
                break;
            case 3:
                std::cout << "Enter radius: ";
                std::cin >> param1;
                shapes = new Sphere(param1);
                shapes->print();
                figureArea = shapes->area();
                std::cout << "Area: " << figureArea << std::endl;
                figureVolume = shapes->volume();
                std::cout << "Volume: " << figureVolume << std::endl;
                break;
            case 4:
                std::cout << "Enter side: ";
                std::cin >> param1;
                shapes = new Cube(param1);
                shapes->print();
                figureArea = shapes->area();
                std::cout << "Area: " << figureArea << std::endl;
                figureVolume = shapes->volume();
                std::cout << "Volume: " << figureVolume << std::endl;
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    }
    delete shapes;
}


