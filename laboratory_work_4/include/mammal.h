#pragma once
#include <iostream>
#include <string>

class Mammal {
protected:
  std::string name;
  int height;
  double weight;

  Mammal() : name("unknown"), height(0), weight(0) {}
  Mammal(std::string name, int height, double weight);

public:
  Mammal(const Mammal &other);
  Mammal &operator=(const Mammal &other);
  Mammal(Mammal &&move) noexcept;
  Mammal &operator=(Mammal &&move) noexcept;

  virtual ~Mammal();

  std::string get_name();
  virtual void print_info() const = 0;
  void enter_info();
};