#include "dog.h"

Dog::Dog():Animal(){};

void Dog::print_info() const {
  std::cout << "Name = " << name << ", weight = " << weight
            << ", height = " << height;
    std::cout << "\nSound : Gav Gav Gav\n" << std::endl;
}
