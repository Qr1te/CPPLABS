#ifndef LAB6_OVERFLOWEXCEPTION_H
#define LAB6_OVERFLOWEXCEPTION_H

#include "StringException.h"

class OverflowException : public StringException {
public:
    explicit OverflowException(const std::string& msg);
};


#endif//LAB6_OVERFLOWEXCEPTION_H
