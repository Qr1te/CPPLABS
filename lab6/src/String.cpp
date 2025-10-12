#include "../includes/String.h"
#include <cstring>

void String::freeMemory() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
    length = 0;
}

String::String() : data(nullptr), length(0) {}

String::String(const char* str) {
    if (str == nullptr) {
        throw InvalidArgumentException( "Null pointer passed to String constructor");
    }
    length = std::strlen(str);
    if (length > MAX_SIZE) {
        throw OverflowException("String length exceeds maximum size");
    }
    try {
        data = new char[length + 1];
        std::strcpy(data, str);
    } catch (const std::bad_alloc&) {
        throw MemoryAllocationException("Failed to allocate memory in String constructor");
    }
}

String::String(const String& other) : length(other.length) {
    if (length > MAX_SIZE) {
        throw OverflowException("String length exceeds maximum size in copy constructor");
    }
    try {
        data = new char[length + 1];
        std::strcpy(data, other.data);
    } catch (const std::bad_alloc&) {
        throw MemoryAllocationException("Failed to allocate memory in copy constructor");
    }
}

String::~String() { freeMemory(); }

String& String::operator=(const String& other) {
    if (this != &other) {
        freeMemory();
        length = other.length;
        if (length > MAX_SIZE) {
            throw OverflowException("String length exceeds maximum size in assignment");
        }
        try {
            data = new char[length + 1];
            std::strcpy(data, other.data);
        } catch (const std::bad_alloc&) {
            throw MemoryAllocationException("Failed to allocate memory in assignment");
        }
    }
    return *this;
}

String& String::operator+=(const String& other) {
    if (other.length == 0) return *this;

    size_t newLength = length + other.length;
    if (newLength > MAX_SIZE) {
        throw OverflowException("Resulting string length exceeds maximum size in concatenation");
    }

    try {
        char* newData = new char[newLength + 1];
        if (data != nullptr) {
            std::strcpy(newData, data);
        } else {
            newData[0] = '\0';
        }
        std::strcat(newData, other.data);
        freeMemory();
        data = newData;
        length = newLength;
    } catch (const std::bad_alloc&) {
        throw MemoryAllocationException("Failed to allocate memory in concatenation");
    }
    return *this;
}

bool String::operator==(const String& other) const {
    if (length != other.length) {
        return false;
    }
    return std::strcmp(data, other.data) == 0;
}

char String::operator[](size_t index) const {
    if (index >= length) {
        throw OutOfRangeException("Index out of range in operator[]");
    }
    return data[index];
}

String String::substring(size_t start, size_t len) const {
    if (start >= length) {
        throw OutOfRangeException("Start index out of range in substring");
    }
    if (len > length - start) {
        throw OutOfRangeException("Substring length out of range");
    }
    if (len > MAX_SIZE) {
        throw OverflowException("Substring length exceeds maximum size");
    }

    try {
        String result;
        result.length = len;
        result.data = new char[len + 1];
        std::strncpy(result.data, data + start, len);
        result.data[len] = '\0';
        return result;
    } catch (const std::bad_alloc&) {
        throw MemoryAllocationException("Failed to allocate memory in substring");
    }
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << (str.data ? str.data : "");
    return os;
}

std::istream& operator>>(std::istream& is, String& str) {
    std::string buffer;
    is >> buffer;
    if (buffer.length() > String::MAX_SIZE) {
        throw OverflowException("Input string length exceeds maximum size");
    }
    str.freeMemory();
    str.length = buffer.length();
    try {
        str.data = new char[str.length + 1];
        std::strcpy(str.data, buffer.c_str());
    } catch (const std::bad_alloc&) {
        throw MemoryAllocationException("Failed to allocate memory in input operator");
    }
    return is;
}