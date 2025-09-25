#pragma once
#include "mammal.h"

class Animal : public Mammal {
public:
  Animal();
  virtual void print_info() const = 0;
};