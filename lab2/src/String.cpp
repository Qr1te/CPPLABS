#include "../includes/String.h"

void String::freeMemory() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    length = 0;
}
String::String() : data(nullptr), length(0) {}
String::String(const char *str) {
    if (str == nullptr) {
        data = new char[1];
        data[0] = '\0';
        length = 0;
    } else {
        length = std::strlen(str);
        data = new char[length + 1];
        std::strcpy(data, str);
    }
}

String::String(const String &other) : length(other.length) {
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

String::~String() { freeMemory(); }

String &String::operator=(const String &other) {
    if (this != &other) {
        freeMemory();
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }
    return *this;
}

String &String::operator+=(const String &other) {
    if (other.length > 0) {
        auto newData = new char[length + other.length + 1];

        if (data != nullptr) {
            std::strcpy(newData, data);
        } else {
            newData[0] = '\0';
        }

        std::strcat(newData, other.data);
        freeMemory();
        data = newData;
        length += other.length;
    }
    return *this;
}

bool String::operator==(const String &other) const {
    if (length != other.length) {
        return false;
    }
    return std::strcmp(data, other.data) == 0;
}

