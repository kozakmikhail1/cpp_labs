#include "const.h"
#include "functions.h"
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>

class Car
{
    std::string reg_number;
    int year_of_release;
    std::string body_color;

  public:
    Car();
    Car(const std::string &reg_number, int release_year, const std::string &body_color);
    Car(const Car &car) = default;

    std::string get_reg_number()const;
    int get_year_of_release()const;
    std::string get_body_color()const;

    int set_reg_number();
    void set_year_of_release(int);
    int set_body_color();

    friend std::fstream &operator>>(std::fstream &in, Car &car);
    friend std::fstream &operator<<(std::fstream &out,const Car &car);
    friend std::istream &operator>>(std::istream &in, Car &car);
    friend std::ostream &operator<<(std::ostream &out, const Car &car);
};
