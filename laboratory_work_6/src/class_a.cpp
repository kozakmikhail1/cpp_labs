#include "class_a.h"
#include <math.h>

A::A(double first_num)
{
    if (first_num == 0)
    {
        std::cout << "Error, not squer  " << std::endl;
        exit(1);
    }
    else
        coefficient_a = first_num;
}
void A::set_coef_a(double new_value)
{
    if (new_value == 0)
    {
        std::cout << "Error, a musn't be 0" << std::endl;
    }
    else
        coefficient_a = new_value;
}
