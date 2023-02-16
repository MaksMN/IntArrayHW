#pragma once
#include <exception>

class IntArrayNoFoundException : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "ERROR: Search result not found!";
    }
};