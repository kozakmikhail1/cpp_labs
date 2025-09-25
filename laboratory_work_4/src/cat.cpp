#include "cat.h"

Cat::Cat():Animal(){};

void Cat::print_info() const{
  std::cout << "Name = " << name << ", weight = " << weight
            << ", height = " << height;
    std::cout << "\nSound : Miy Miy Miy\n" << std::endl;
}