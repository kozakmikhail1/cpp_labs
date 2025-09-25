#include "menu.h"

Menu::Menu() { arr_mammal = new Mammal *[lenght]; }

void Menu::show_info_array() const {
  if (arr_mammal != nullptr)
    for (int i = 0; i < lenght; i++) {
      arr_mammal[i]->print_info();
    }
}

void Menu::show_info_one_mammal(std::string_view name) const {
  bool flag = false;
  if (arr_mammal != nullptr)
    for (int i = 0; i < lenght; i++) {
      if (arr_mammal[i]->get_name() == name) {
        flag = true;
        arr_mammal[i]->print_info();
      }
    }
  if (flag == false)
    std::cout << "We didn't find object with this name" << std::endl;
}

Mammal *Menu::choose_create_new_mammal() {
  int choose;
  Mammal *ptr = nullptr;

  while (true) {
    choose = input_int(
        "Who do you want to create \n1.Human\n2.Dog\n3.Cat\nEnter number ");

    switch (choose) {
    case 1: {
      auto new_human = new Human();
      new_human->enter_info();
      ptr = new_human;
      break;
    }
    case 2: {
      auto new_dog = new Dog();
      new_dog->enter_info();
      ptr = new_dog;
      break;
    }
    case 3: {
      auto new_cat = new Cat();
      new_cat->enter_info();
      ptr = new_cat;
      break;
    }
    default: {
      std::cout << "You made mistake, try again\n" << std::endl;
      break;
    }
    }
    if(ptr != nullptr)
        break;
  }
  return ptr;
}

void Menu::add_new_mammal(Mammal *new_element) {
  lenght++;
  auto temp_arr = new Mammal *[lenght];

  for (int i = 0; i < lenght - 1; i++) {
    temp_arr[i] = arr_mammal[i];
  }
  temp_arr[lenght - 1] = new_element;

  if (arr_mammal != nullptr) {
    delete[] arr_mammal;
  }

  arr_mammal = temp_arr;
}

void Menu::print_operation_menu() const {
  std::cout << "\tMenu" << std::endl;
  std::cout << "1.Create new mammal" << std::endl;
  std::cout << "2.Show info about all mammal" << std::endl;
  std::cout << "3.Show information on one mammal by name" << std::endl;
  std::cout << "4.Exit" << std::endl;
}

void Menu::choose_operations() {
  while (true) {
    print_operation_menu();
    int choose = input_int("Enter number of operation ");
    switch (choose) {
    case 1: {
      Mammal *temp = choose_create_new_mammal();
      add_new_mammal(temp);
      break;
    }
    case 2:
      show_info_array();
      break;
    case 3: {
      show_info_one_mammal(input_string("Enter name wich you want to find: "));
    } break;
    case 4:
      return;
    default:
      std::cout << C_RED << "You make mistake" << C_WHITE << std::endl;
      break;
    }
  }
}

void Menu::start() {
  system("clear");
  choose_operations();
}