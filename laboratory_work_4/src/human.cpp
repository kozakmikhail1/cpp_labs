#include "human.h"

Human::Human(): Mammal(){}
void Human::print_info() const {
  std::cout << "\nHi, my name " << get_name() << ", my weight " << get_weight()
            << " and my height " << get_height();
  std::cout << "\nHow are you?" << std::endl;
}