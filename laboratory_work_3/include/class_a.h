#pragma once
#include "functions.h"
#include <iostream>
#include <vector>

class A
{
  double coefficient_a;

  public:
    explicit A(double first_num);

  protected:
    double get_coef_a()const { return coefficient_a; }
    void set_coef_a(double new_value);
};
