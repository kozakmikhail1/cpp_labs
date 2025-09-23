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

class B : public A
{
    double coefficient_b;

  public:
    B(double first_num, double secound_num) : A(first_num), coefficient_b(secound_num){};
  protected:
    double get_coef_b()const { return coefficient_b; }
    void set_coef_b(double new_value) { coefficient_b = new_value; }
};

class C : public B
{
    double coefficient_c;
    bool imaginary_roots = false;
    std::vector<double> roots;

  public:

    C() : B(1, 1), coefficient_c(1){};
    explicit C(double first_num, double secound_num, double third_num) : B(first_num, secound_num), coefficient_c(third_num){};

    C(const C &other);
    C(C &&move) noexcept;
    C &operator=(const C &other);
    C &operator=(C &&other) noexcept;
    ~C();

    double get_coef_c() const { return coefficient_c; }
    void set_coef_c(double new_value) { coefficient_c = new_value; }

    void enter_value();
    void show_equation () const;
    void find_root();
    void show_root();
    void clear_roots();
};