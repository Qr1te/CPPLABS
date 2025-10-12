#include "../includes/Menu.h"
#include <limits>


void printErrorRed(const std::string& message) {
    std::cerr << "\033[1;31m" << message << "\033[0m" << std::endl;
}

void Menu::showMenu() {
    std::cout << "\n=== String Operations Menu ===\n";
    std::cout << "1. Create a new string\n";
    std::cout << "2. Access character at index\n";
    std::cout << "3. Get substring\n";
    std::cout << "4. Concatenate with another string\n";
    std::cout << "5. Compare with another string\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice (1-6): ";
}

void Menu::processString(String& str, size_t index, size_t substrStart, size_t substrLen) {
    try {
        std::cout << "Current string: " << str << std::endl;
        std::cout << "Accessing character at index " << index << ": " << str[index] << std::endl;
        String substr = str.substring(substrStart, substrLen);
        std::cout << "Substring: " << substr << std::endl;
        String another("Another string");
        str += another;
        std::cout << "After concatenation: " << str << std::endl;
    }
    catch (const OutOfRangeException& e) {
        printErrorRed("Range error: " + std::string(e.what()));
    }
    catch (const OverflowException& e) {
        printErrorRed("Overflow error: " + std::string(e.what()));
    }
    catch (const MemoryAllocationException& e) {
        printErrorRed("Memory allocation error: " + std::string(e.what()));
    }
    catch (const StringException& e) {
        printErrorRed("General string error: " + std::string(e.what()));
    }
    catch (const std::exception& e) {
        printErrorRed("Standard exception: " + std::string(e.what()));
    }
    catch (...) {
        printErrorRed("Unknown error occurred");
    }
}

void Menu::run() {
    String str;
    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        try {
            switch (choice) {
                case 1: {
                    std::cout << "Enter a string: ";
                    std::cin >> str;
                    std::cout << "String created: " << str << std::endl;
                    break;
                }
                case 2: {
                    std::cout << "Enter index: ";
                    size_t index;
                    std::cin >> index;
                    std::cout << "Character at index " << index << ": " << str[index] << std::endl;
                    break;
                }
                case 3: {
                    std::cout << "Enter start index: ";
                    size_t start;
                    std::cin >> start;
                    std::cout << "Enter length: ";
                    size_t len;
                    std::cin >> len;
                    String substr = str.substring(start, len);
                    std::cout << "Substring: " << substr << std::endl;
                    break;
                }
                case 4: {
                    std::cout << "Enter string to concatenate: ";
                    String another;
                    std::cin >> another;
                    str += another;
                    std::cout << "After concatenation: " << str << std::endl;
                    break;
                }
                case 5: {
                    std::cout << "Enter string to compare: ";
                    String another;
                    std::cin >> another;
                    if (str == another) {
                        std::cout << "Strings are equal\n";
                    } else {
                        std::cout << "Strings are not equal\n";
                    }
                    break;
                }
                case 6:
                    std::cout << "Exiting...\n";
                    return;
                default:
                    std::cout << "Invalid choice. Please enter a number between 1 and 6.\n";
            }
        }
        catch (const StringException& e) {
            printErrorRed("Error: " + std::string(e.what()));
        }
        catch (const std::exception& e) {
            printErrorRed("Standard exception: " + std::string(e.what()));
        }
        catch (...) {
            printErrorRed("Unknown error occurred");
        }
    }
}