#pragma once

#include <iostream>
#include <limits>
#include <string>

template <typename T>
T get_input(const std::string &prompt)
{
    T value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cout << "Error! Please enter a valid value." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

template <>
std::string get_input<std::string>(const std::string &prompt);