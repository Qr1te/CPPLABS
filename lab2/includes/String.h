#ifndef LAB2_STRING_H
#define LAB2_STRING_H

#include <iostream>
#include <cstring>

class String {
private:
    char* data;
    size_t length;

    void freeMemory();
public:
    String();
    explicit String(const char* str);
    String(const String& other);
    ~String();
    String& operator=(const String& other);
    String& operator+=(const String& other);
    bool operator==(const String& other) const;
    friend std::ostream& operator<<(std::ostream& os, const String& str) {
        os << str.data;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, String& str) {
        std::string buffer;
        is >> buffer;
        str.freeMemory();
        str.length = buffer.length();
        str.data = new char[str.length + 1];
        std::strcpy(str.data, buffer.c_str());
        return is;
    }
};



#endif//LAB2_STRING_H
