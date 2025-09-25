#include "mammal.h"

Mammal::Mammal(std::string name, int height, double weight)
    : name(std::move(name)), height(height), weight(weight) {
} 

Mammal::Mammal(const Mammal &other) = default;

Mammal &Mammal::operator=(const Mammal &other) {
  if (this != &other) {
    height = other.height;
    weight = other.weight;
    name = other.name;
  }
  return *this;
}

Mammal::Mammal(Mammal &&other) noexcept = default;

Mammal &Mammal::operator=(Mammal &&other) noexcept {
  if (this != &other) {
    height = other.height;
    weight = other.weight;
    name = std::move(other.name);

    other.height = 0;
    other.weight = 0;
  }
  return *this;
}

Mammal::~Mammal() = default;

void Mammal::enter_info() {
  std::cout << "Enter a name ";
  std::cin >> name;
  std::cout << "Enter the height ";
  std::cin >> height;
  std::cout << "Enter the weight ";
  std::cin >> weight;
}