#pragma once
#include "animal.h"

class Cat : public Animal
{
    public:
    Cat();
    void print_info() const override;
};