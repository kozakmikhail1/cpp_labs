#include "human.h"

Human::Human(): Mammal(){}
void Human::print_info() const {
  std::cout << "Hi, my name " << name << ", my weight " << weight
            << " and my height " << height;
  std::cout << "\nHow are you?\n" << std::endl;
}