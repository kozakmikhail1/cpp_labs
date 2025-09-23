#include "class_abc.h"
#include "functions.h"
#include <iostream>

class Menu
{
    C *equation = nullptr;

    void choose_construct();
    void choose_operations();

  public:
    void start();
};