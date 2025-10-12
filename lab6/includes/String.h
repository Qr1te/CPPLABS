#ifndef LAB6_STRING_H
#define LAB6_STRING_H

#include "StringException.h"
#include "InvalidArgumentException.h"
#include "OutOfRangeException.h"
#include "OverflowException.h"
#include "MemoryAllocationException.h"
#include "UnderflowException.h"
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
    String substring(size_t start, size_t len) const;

    friend std::ostream& operator<<(std::ostream& os, const String& str);
    friend std::istream& operator>>(std::istream& is, String& str);
};


#endif//LAB6_STRING_H
