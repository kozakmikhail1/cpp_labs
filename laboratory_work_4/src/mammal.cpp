#include "mammal.h"

Mammal::Mammal(std::string name, int height, double weight)
    : name(std::move(name)), height(height), weight(weight) {}

Mammal::Mammal(const Mammal &other) = default;

Mammal &Mammal::operator=(const Mammal &other) = default;

Mammal::Mammal(Mammal &&other) noexcept = default;

Mammal &Mammal::operator=(Mammal &&other) noexcept = default;

Mammal::~Mammal() { 
  name = "";
  height = 0;
  weight = 0; 
};

void Mammal::enter_info() {
  name = input_name("Enter a name ");
  height = get_number("Enter the height ", 0,INT_MAX);
  weight = get_number("Enter the weight ",0,INT_MAX);
}