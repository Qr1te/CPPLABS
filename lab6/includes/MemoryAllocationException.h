#ifndef LAB6_MEMORYALLOCATIONEXCEPTION_H
#define LAB6_MEMORYALLOCATIONEXCEPTION_H

#include "StringException.h"

class MemoryAllocationException : public StringException {
public:
    explicit MemoryAllocationException(const std::string& msg);
};


#endif//LAB6_MEMORYALLOCATIONEXCEPTION_H
