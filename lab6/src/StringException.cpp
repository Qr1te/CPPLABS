#include "../includes/StringException.h"

StringException::StringException(const std::string& msg) : message(msg) {}

const char* StringException::what() const noexcept {
    return message.c_str();
}




