#include "functions.h"

int input_int(const std::string &prompt = "Enter a single integer: ")
{
    int value = 0;
    while (true)
    {
        std::cout << C_YELLOW << prompt << C_WHITE;
        std::cin >> value;

        if (std::cin.good() && std::cin.peek() == '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input, try again! " << std::endl;
    }
}

std::string input_string(const std::string& msg)
{
    std::string line;

    std::cout << msg;
    std::getline(std::cin, line);
    return line;
}