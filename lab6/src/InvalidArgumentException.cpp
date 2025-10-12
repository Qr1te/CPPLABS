#include "../includes/InvalidArgumentException.h"

InvalidArgumentException::InvalidArgumentException(const std::string& msg) : StringException(msg) {}