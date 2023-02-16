#pragma once
#include <exception>

class IntArrayBadRange : public std::exception
{
public:
    virtual const char *what() const noexcept override
    {
        return "ERROR: Bad range!";
    }
};