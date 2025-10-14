#include "functions.h"

int get_int(const std::string &prompt = "Enter a single integer: ", int min = 0, int max = 0)
{
    int value = 0;
    while (true)
    {
        std::cout << C_YELLOW << prompt << C_WHITE;
        std::cin >> value;

        if (std::cin.good() && std::cin.peek() == '\n' && value >= min && value <= max)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << C_RED << "Incorrect input, try again! " << C_WHITE << std::endl;
    }
}

bool check_is_color(const std::string &str)
{
    if (std::ifstream file_colors(NAME_COLOR_FILE); file_colors.is_open())
    {
        std::string line_color;
        while (std::getline(file_colors, line_color))
        {
            if (line_color == str)
                return true;
        }
        file_colors.close();
    }
    else
    {
        std::cout << "Error open color file: " << NAME_COLOR_FILE << std::endl;
    }
    return false;
}

bool check_correct_reg_num(const std::string &reg_num)
{
    if (reg_num.length() == 9 && reg_num[4] == ' ' && reg_num[7] == '-' && 
        reg_num[5] >= 'A' && reg_num[5] <= 'Z' && reg_num[6] >= 'A' && 
        reg_num[6] <= 'Z' && reg_num[8] >= '0' && reg_num[8] <= '8')
        for (int i = 0; i < 4; i++)
        {
            if (!(reg_num[i] >= '0' && reg_num[i] <= '9'))
                return true;
        }
    return false;
}
