#include "../includes/menu.h"

void clearInputBuffer() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void menu(){
    Storage storage;
    int choice;

    do {

        std::cout << "\nMenu:\n";
        std::cout << "1. Add metal item\n";
        std::cout << "2. List all metal items\n";
        std::cout << "3. Delete metal item\n";
        std::cout << "4. Update metal item\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;


        switch (choice) {
            case 1: {
                storage.addItem();
                break;
            }
            case 2: {
                storage.listItem();
                break;
            }
            case 3: {
                int id;
                std::cout << "Enter ID to delete: ";
                std::cin >> id;
                storage.deleteItem(id);
                break;
            }
            case 4: {
                int id;
                std::cout << "Enter ID to update: ";
                std::cin >> id;
                storage.updateItem(id);
                break;
            }
            case 5: {
                std::cout << "Exiting..." << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice!" << std::endl;
            }

        }
    } while (choice != 5);
}