#include "../includes/menu.h"

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

void clearInputBuffer() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

template <typename T>
void runProgram() {
    Tree<T> tree;
    Algorithm<T> alg;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\n=== Binary Tree Menu ===\n";
        std::cout << "1. Insert a value\n";
        std::cout << "2. Perform inorder traversal\n";
        std::cout << "3. Perform level order traversal\n";
        std::cout << "4. Search for a value\n";
        std::cout << "5. Visualize the tree\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice (1-6): ";
        std::cin >> choice;


        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                T value;
                std::cout << "Enter the value to insert: ";
                value = getInput<T>("");
                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                tree.insert(value);
                std::cout << "Value " << value << " inserted successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Inorder traversal result:\n";
                alg.inorderTraversal(tree.getRoot());
                break;
            }
            case 3: {
                std::cout << "Level order traversal result:\n";
                alg.levelOrderTraversal(tree.getRoot());
                break;
            }
            case 4: {
                T value;
                std::cout << "Enter the value to search: ";
                value = getInput<T>("");
                if (std::cin.fail()) {
                    std::cout << "Invalid input. Please enter a valid value.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                TreeNode<T>* found = alg.search(tree.getRoot(), value);
                if (found) {
                    std::cout << "Value " << value << " found in the tree.\n";
                } else {
                    std::cout << "Value " << value << " not found in the tree.\n";
                }
                break;
            }
            case 5: {
                std::cout << "Tree visualization (rotated 90 degrees):\n";
                alg.visualize(tree.getRoot());
                break;
            }
            case 6: {
                std::cout << "Exiting program.\n";
                running = false;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please select a number between 1 and 6.\n";
                break;
            }
        }
    }
}

void menu(){
    bool programRunning = true;
    while (programRunning) {
        std::cout << "\n=== Data Type Selection ===\n";
        std::cout << "Select the data type for the binary tree:\n";
        std::cout << "1. Integer (int)\n";
        std::cout << "2. Double (double)\n";
        std::cout << "3. String (string)\n";
        std::cout << "4. Exit program\n";
        std::cout << "Enter your choice (1-4): ";
        int typeChoice;
        typeChoice = getInput<int>("");
        clearInputBuffer();
        switch (typeChoice) {
            case 1: {
                std::cout << "Starting binary tree with int data type.\n";
                runProgram<int>();
                break;
            }
            case 2: {
                std::cout << "Starting binary tree with double data type.\n";
                runProgram<double>();
                break;
            }
            case 3: {
                std::cout << "Starting binary tree with string data type.\n";
                runProgram<std::string>();
                break;
            }
            case 4: {
                std::cout << "Exiting program.\n";
                programRunning = false;
                break;
            }
            default: {
                std::cout << "Invalid choice. Please select a number between 1 and 4.\n";
                break;
            }
        }
    }
}