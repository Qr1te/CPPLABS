#ifndef LAB6_UNDERFLOWEXCEPTION_H
#define LAB6_UNDERFLOWEXCEPTION_H

#include "StringException.h"

class UnderflowException : public StringException {
public:
    explicit UnderflowException(const std::string& msg);
};



#endif//LAB6_UNDERFLOWEXCEPTION_H
