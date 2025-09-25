#include "functions.h"

int get_number(const std::string &msg, int min, int max) {
  int num = 0;
  int sym = 0;

  std::cout << C_YELLOW << msg << C_WHITE;

  while (true) {
    if (std::cin.peek() != '\n' && std::cin.peek() != ' ' &&
        (std::cin >> num).good()) {
      sym = std::cin.peek();
      if (((char)sym == '\n' || (char)sym == EOF) && num >= min && num <= max) {
        std::cin.get();
        return num;
      }
    }

    std::cin.clear();
    while (std::cin.get() != '\n' && !std::cin.eof())
      ;
    std::cout << C_RED
              << "\nError, invalid input. Please try again: " << C_WHITE;
  }
}

std::string input_string(const std::string &msg) {
  std::string line;

  std::cout << msg;
  std::getline(std::cin, line);
  return line;
}

std::string input_name(const std::string &msg) {
  std::string line;
  std::cout << msg;

  while (true) {
    bool capital_letter = false;
    bool all_latter = true;

    std::getline(std::cin, line);

    if (line[0] >= 'A' && line[0] <= 'Z' && line[1] != '\0')
      capital_letter = true;

    if (capital_letter != true) {
      std::cout << C_RED << "Name should be start large \n"
                << C_WHITE << std::endl;
      continue;
    }
    
    for (auto index = line.begin() + 1; index != line.end(); index++) {
      if (*index >= 'a' && *index <= 'z')
        continue;
      else {
        all_latter = false;
        break;
      }
    }

    if (all_latter == false)
      std::cout << C_RED << "It isn't a name, try again " << C_WHITE
                << std::endl;
    else
      break;
  }

  return line;
}