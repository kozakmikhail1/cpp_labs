#include "class_abc.h"
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
C::C(const C &other) = default;
C::C(C &&move) noexcept = default;
C &C::operator=(const C &other) = default;
C &C::operator=(C &&move) noexcept = default;
C::~C()
{
    coefficient_c = 0;
    delete this;
}

void C::enter_value()
{
    clear_roots();
    set_coef_a(input_int("Enter coefficient a: "));
    set_coef_b(input_int( "Enter coefficient b: "));
    set_coef_c(input_int("Enter coefficient c: "));
}
void C::show_equation() const
{
    std::cout << get_coef_a() << "x^2";
    if (get_coef_b() > 0)
        std::cout << " + " << get_coef_b() << "x";
    else if (get_coef_b() < 0)
        std::cout << " - " << - get_coef_b() << "x";
    if (coefficient_c > 0)
        std::cout << " + " << coefficient_c;
    else if (coefficient_c < 0)
        std::cout << " - " << coefficient_c;
    std::cout << " = 0" << std::endl;
}
void C::show_root()
{
    if (roots.size() == 1)
    {
        std::cout << " x1 = " << roots[0] << std::endl;
    }
    else if (imaginary_roots == false)
    {
        std::cout << " x1 = " << roots[0] << std::endl;
        std::cout << " x2 = " << roots[1] << std::endl;
    }
    else
    {
        std::cout << " x1 = " << roots[0] << " + " << roots[1] << "i" << std::endl;
        std::cout << " x2 = " << roots[0] << " - " << roots[1] << "i" << std::endl;
    }
}

void C::find_root()
{
    if (get_coef_a() == 0)
    {
        std::cout << "Error, not squer  " << std::endl;
        return;
    }

    double discr = (get_coef_b() * get_coef_b()) - (4 * get_coef_a() * coefficient_c);

    if (discr == 0)
    {
        roots.push_back(-get_coef_b() / 2 * get_coef_a());
    }
    else if (discr > 0)
    {
        roots.push_back((-get_coef_b() - sqrt(discr)) / (2 * get_coef_a()));
        roots.push_back((-get_coef_b() + sqrt(discr)) / (2 * get_coef_a()));
    }
    else
    {
        roots.push_back((double)-1 * get_coef_b() / (2 * get_coef_a()));
        roots.push_back(sqrt(-discr) / (2 * get_coef_a()));
        imaginary_roots = true;
    }
}

void C::clear_roots()
{
    roots.clear();
    imaginary_roots = false;
}
