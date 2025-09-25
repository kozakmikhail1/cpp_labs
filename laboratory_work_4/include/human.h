#pragma once
#include "mammal.h"

class Human : public Mammal
{
    public:
    Human();
    void print_info() const override;
};