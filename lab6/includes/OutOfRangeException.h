#ifndef LAB6_OUTOFRANGEEXCEPTION_H
#define LAB6_OUTOFRANGEEXCEPTION_H

#include "StringException.h"

class OutOfRangeException : public StringException {
public:
    explicit OutOfRangeException(const std::string& msg);
};


#endif//LAB6_OUTOFRANGEEXCEPTION_H
