#include "../includes/menu.h"

void clearInputBuffer() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

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

void displayTypeMenu() {
    std::cout << "\nSelect data type for the queue:\n";
    std::cout << "1. Integer (int)\n";
    std::cout << "2. Double (double)\n";
    std::cout << "3. Character (char)\n";
    std::cout << "4. String (string)\n";
    std::cout << "Enter your choice: ";
}

void displayQueueMenu() {
    std::cout << "\nQueue Menu:\n";
    std::cout << "1. Add element to queue\n";
    std::cout << "2. Remove element from queue\n";
    std::cout << "3. View first element\n";
    std::cout << "4. Check if queue is empty\n";
    std::cout << "5. Get queue size\n";
    std::cout << "6. View entire queue\n";
    std::cout << "7. Exit\n";
    std::cout << "Enter your choice: ";
}

template <typename T>
void processQueueMenu(Queue<T>& queue) {
    int choice;
    T value;

    while (true) {
        displayQueueMenu();
        choice = getInput<int>("");
        clearInputBuffer();

        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter value to add: ";
                    if constexpr (std::is_same<T, std::string>::value) {
                        std::string input;
                        std::getline(std::cin, input);
                        value = input;
                    } else {
                        value = getInput<T>("");
                        clearInputBuffer();
                    }
                    queue.push(value);
                    std::cout << "Element '" << value << "' added to queue\n";
                    break;
                }
                case 2: {
                    if (queue.isEmpty()) {
                        std::cout << "Queue is empty, cannot remove element\n";
                    } else {
                        value = queue.pop();
                        std::cout << "Removed element: '" << value << "'\n";
                    }
                    break;
                }
                case 3: {
                    if (queue.isEmpty()) {
                        std::cout << "Queue is empty\n";
                    } else {
                        std::cout << "First element: '" << queue.peek() << "'\n";
                    }
                    break;
                }
                case 4:
                    std::cout << (queue.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
                    break;
                case 5:
                    std::cout << "Queue size: " << queue.getSize() << "\n";
                    break;
                case 6:
                    queue.printQueue();
                    break;
                case 7:
                    std::cout << "Program terminated\n";
                    return;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

void menu() {
    int typeChoice;

    while (true) {
        displayTypeMenu();
        std::cin >> typeChoice;
        clearInputBuffer();

        switch (typeChoice) {
            case 1: {
                Queue<int> queue;
                processQueueMenu(queue);
                return;
            }
            case 2: {
                Queue<double> queue;
                processQueueMenu(queue);
                return;
            }
            case 3: {
                Queue<char> queue;
                processQueueMenu(queue);
                return;
            }
            case 4: {
                Queue<std::string> queue;
                processQueueMenu(queue);
                return;
            }
            default:
                std::cout << "Invalid data type choice. Please try again.\n";
        }
    }
}