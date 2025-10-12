#include "../includes/Menu.h"

int main() {
    try {
        Menu::run();
    }
    catch (const StringException& e) {
        std::cerr << "Main caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Main caught standard exception: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Main caught unknown error" << std::endl;
    }
    return 0;
}