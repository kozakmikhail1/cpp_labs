#include <iostream>
#include <cstring>
#include <fstream>
#include "const.h"
#include "functions.h"
#include <iomanip>


class Car
{
    std::string reg_number;
    int year_of_release;
    std::string body_color;

    public :
    Car();
    Car(std::string reg_number,int release_year,std::string body_color);
    Car(const Car& car);
    ~Car();

    std::string get_reg_number();
    int set_reg_number();
    int get_year_of_release();
    void set_year_of_release(int);
    std::string get_body_color();
    int set_body_color();

    friend std::fstream& operator>> (std::fstream& in, Car &car);
    friend std::fstream& operator<< (std::fstream& out, Car &car);
    friend std::istream& operator>> (std::istream& in, Car &car);
    friend std::ostream& operator<< (std::ostream& out, const Car &car);
};

