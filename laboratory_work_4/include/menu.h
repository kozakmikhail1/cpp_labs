#include "cat.h"
#include "dog.h"
#include "functions.h"
#include "human.h"
#include "functions.h"
#include <iostream>

class Menu {
  Mammal **arr_mammal;
  int lenght = 0;

  Mammal *choose_create_new_mammal();

  void show_info_one_mammal(std::string_view name) const;
  void add_new_mammal(Mammal *new_mammal);
  void print_operation_menu() const;
  void choose_operations();
  void show_info_array() const;

public:
  Menu();
  void start();
};