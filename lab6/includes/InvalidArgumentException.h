#ifndef LAB6_INVALIDARGUMENTEXCEPTION_H
#define LAB6_INVALIDARGUMENTEXCEPTION_H

#include "StringException.h"

class InvalidArgumentException : public StringException {
public:
    explicit InvalidArgumentException(const std::string& msg);
};


#endif//LAB6_INVALIDARGUMENTEXCEPTION_H
