#pragma once
#include "animal.h"
class Dog : public Animal
{
    public:
    Dog();
    void print_info() const override;
};