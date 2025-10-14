#pragma once
#include "binary_file.h"

class Menu
{
    BinaryFile file;

    void print_menu()const;
    void choose_operation();

  public:
    void start();
};