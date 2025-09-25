#pragma once
#include <iostream>
#include <string>

class Mammal {

  std::string name;
  int height;
  double weight;

protected:
  Mammal() : name("unknown"), height(0), weight(0) {}
  Mammal(std::string name, int height, double weight);

  void set_name(std::string_view line) { name = line; };
  int get_height() const { return height; };
  void set_height(int value) { height = value; };
  double get_weight() const { return weight; };
  void set_weight(double value) { weight = value; };

public:
  std::string get_name() const { return name; };

  Mammal(const Mammal &other);
  Mammal &operator=(const Mammal &other);
  Mammal(Mammal &&move) noexcept;
  Mammal &operator=(Mammal &&move) noexcept;

  virtual ~Mammal();

  virtual void print_info() const = 0;
  void enter_info();
};