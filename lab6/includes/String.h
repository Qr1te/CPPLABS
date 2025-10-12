#ifndef LAB6_STRING_H
#define LAB6_STRING_H

#include "InvalidArgumentException.h"
#include "MemoryAllocationException.h"
#include "OutOfRangeException.h"
#include "OverflowException.h"
#include "StringException.h"
#include "UnderflowException.h"
#include <cstring>
#include <iostream>

class String {
private:
    char* data;
    size_t length;
    static const size_t MAX_SIZE = 80;

    void freeMemory();

public:
    String();
    explicit String(const char* str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);
    String& operator+=(const String& other);
    bool operator==(const String& other) const;
    char operator[](size_t index) const;
    [[nodiscard]] String substring(size_t start, size_t len) const;

    friend std::ostream& operator<<(std::ostream& os, const String& str){
        os << (str.data ? str.data : "");
        return os;
    }

    friend std::istream& operator>>(std::istream& is, String& str){
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
};


#endif//LAB6_STRING_H
