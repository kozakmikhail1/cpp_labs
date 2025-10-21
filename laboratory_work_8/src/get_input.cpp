#include "get_input.h"

// Определение специализации в .cpp файле
template<>
std::string get_input<std::string>(const std::string &prompt) {
    std::string value;
    std::cout << prompt;
    std::getline(std::cin, value);
    return value;
}