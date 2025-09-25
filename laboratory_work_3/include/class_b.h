#include "class_a.h"
class B : public A
{
    double coefficient_b;

  public:
    B(double first_num, double secound_num) : A(first_num), coefficient_b(secound_num){};
  protected:
    double get_coef_b()const { return coefficient_b; }
    void set_coef_b(double new_value) { coefficient_b = new_value; }
};