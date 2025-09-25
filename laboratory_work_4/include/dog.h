#pragma once
#include "animal.h"
#include "mammal.h"
class Dog : public Animal
{
    public:
    Dog();
    void print_info() const override;
};