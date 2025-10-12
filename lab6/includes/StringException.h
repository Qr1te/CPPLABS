#ifndef LAB6_STRINGEXCEPTION_H
#define LAB6_STRINGEXCEPTION_H

#include <string>
#include <stdexcept>

class StringException : public std::exception {
protected:
    std::string message;
public:
    explicit StringException(const std::string& msg);
    [[nodiscard]] const char* what() const noexcept override;
};

#endif//LAB6_STRINGEXCEPTION_H
