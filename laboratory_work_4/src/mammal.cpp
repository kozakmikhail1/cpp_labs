#include "mammal.h"

Mammal::Mammal(std::string name, int height, double weight)
    : name(std::move(name)), height(height), weight(weight) {
} 

Mammal::Mammal(const Mammal &other) = default;

Mammal &Mammal::operator=(const Mammal &other)  = default;

Mammal::Mammal(Mammal &&other) noexcept = default;

Mammal &Mammal::operator=(Mammal &&other) noexcept = default;

Mammal::~Mammal() = default;

void Mammal::enter_info() {
  std::cout << "Enter a name ";
  std::cin >> name;
  std::cout << "Enter the height ";
  std::cin >> height;
  std::cout << "Enter the weight ";
  std::cin >> weight;
}