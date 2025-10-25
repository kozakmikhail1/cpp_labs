#include <iostream>
class StackEmptyException : public std::runtime_error
{
public:
    StackEmptyException() : std::runtime_error("Stack is empty") {}
};