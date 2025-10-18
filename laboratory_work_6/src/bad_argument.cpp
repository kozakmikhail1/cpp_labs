#include "bad_argument.h"

BadArgument::BadArgument(const std::string& msg)
{
    this->msg = msg; 
}

std::string BadArgument::what()
{
    return msg;
}