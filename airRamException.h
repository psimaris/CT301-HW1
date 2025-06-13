#ifndef _AIR_RAM_EXCEPTIONS_H
#define _AIR_RAM_EXCEPTIONS_H


#include <iostream>
#include <stdexcept>
#include <string>


class fixedFileException : public std::runtime_error {
public:
    fixedFileException(const std::string& message) : std::runtime_error(message) {}
    
    const char* what() const noexcept override {
        return std::runtime_error::what();
    }
};

#endif 