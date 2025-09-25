#include "cat.h"

Cat::Cat():Animal(){};

void Cat::print_info() const{
  std::cout << "Name = " << get_name() << ", weight = " << get_weight()
            << ", height = " << get_height();
    std::cout << "\nSound : Miy Miy Miy\n" << std::endl;
}