#include "menu.h"

void print_choose_type_array()
{
    std::cout << "\nType of array" << std::endl;
    std::cout << "1.Integer " << std::endl;
    std::cout << "2.Double" << std::endl;
    std::cout << "3.Char" << std::endl;
    std::cout << "4.String" << std::endl;
    std::cout << "5.exit" << std::endl;
}

int get_int(const std::string &prompt = "Enter a single integer: ",int min = 0, int max = 0)
{
    int value = 0;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.good() && std::cin.peek() == '\n' && value >= min && value <= max)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Incorrect input, try again! " << std::endl;
    }
}

void menu()
{
    while(true)
    {
        print_choose_type_array();
        int choose = get_int("Enter number of type ", 1, 5);
        
        switch (choose)
        {
        case 1: process_array<int>(); break;
        case 2: process_array<double>(); break;
        case 3: process_array<char>(); break;
        case 4: process_array<std::string>(); break;
        case 5: return;
        default: break;
        }
    }
}

