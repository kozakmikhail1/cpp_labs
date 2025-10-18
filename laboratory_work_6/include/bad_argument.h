#pragma once
#include <iostream>
#include <string>

class BadArgument
{
private:
    std::string msg;
public:
    BadArgument (const std::string&);
    ~BadArgument() = default;

    std::string what();
};



