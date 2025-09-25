#include "dog.h"

Dog::Dog():Animal(){};

void Dog::print_info() const {
  std::cout << "Name = " << get_name() << ", weight = " << get_weight()
            << ", height = " << get_height();
    std::cout << "\nSound : Gav Gav Gav\n" << std::endl;
}
