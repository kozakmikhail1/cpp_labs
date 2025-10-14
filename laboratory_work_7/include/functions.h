#pragma once
#include "const.h"
#include <fstream>
#include <iostream>
#include <limits>

int get_int(const std::string &prompt, int min, int max);
bool check_is_color(const std::string &color);
bool check_correct_reg_num(const std::string &reg_num);
