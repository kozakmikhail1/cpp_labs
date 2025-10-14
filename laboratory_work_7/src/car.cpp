#include "car.h"

Car::Car() : reg_number("1111 AA-1"), year_of_release(1900), body_color("black") {}
Car::Car(const std::string& reg_number, int release_year, const std::string& body_color) : reg_number(reg_number), year_of_release(release_year), body_color(body_color) {}

std::string Car::get_reg_number()const
{
    return reg_number;
}

int Car::set_reg_number()
{
    std::string number_of_car;
    std::getline(std::cin, number_of_car);

    if (check_correct_reg_num(number_of_car))
    {
        std::cout << C_RED << "Encorrect input, try again\n" << C_WHITE;
        return 1;
    }
    else
    {
        reg_number = number_of_car;
        std::cout << C_GREN << "The data was entered correctly\n" << C_WHITE;
        return 0;
    }
}

int Car::get_year_of_release()const
{
    return year_of_release;
}

void Car::set_year_of_release(int year)
{
    year_of_release = year;
}

std::string Car::get_body_color()const
{
    return body_color;
}
int Car::set_body_color()
{
    std::string color;
    std::cin >> color;

    if (!(check_is_color(color)))
    {
        std::cout << C_RED << "It is't color" << C_WHITE << std::endl;
        return 1;
    }
    else
        return 0;
}

std::istream &operator>>(std::istream &in, Car &car)
{
    std::cout << C_YELLOW << "Create a new car\n" << C_WHITE;
    std::cout << "Enter the registration number of the car(1234 AM-9)\n";
    while (car.set_reg_number())
        ;
    std::cout << "Enter the car's year of "
                 "manufacture(1888 - 2025)\n";
    car.set_year_of_release(get_int("", MIN_YEAR_RELEASE, MAX_YEAR_RELEASE));
    std::cout << C_GREN << "The data was entered correctly\n" << C_WHITE;
    std::cout << "Enter the body color(black, white, red ...)\n";
    while (car.set_body_color())
        ;
    std::cout << C_GREN << "The new car was successfully created\n" << C_WHITE;

    return in;
}

std::ostream &operator<<(std::ostream &out, const Car &car)
{
    out << "| Registration number  " << car.reg_number << "| Year of release  " << car.year_of_release << "| Body color ";
    out << std::setw(12) << car.body_color << "|\n";
    return out;
}

std::fstream &operator>>(std::fstream &in, Car &car)
{
    size_t reg_number_size;
    in.read(reinterpret_cast<char *>(&reg_number_size), sizeof(reg_number_size));
    car.reg_number.resize(reg_number_size);
    in.read(&car.reg_number[0], reg_number_size);

    in.read(reinterpret_cast<char *>(&car.year_of_release), sizeof(car.year_of_release));

    size_t color_size;
    in.read(reinterpret_cast<char *>(&color_size), sizeof(color_size));
    car.body_color.resize(color_size);
    in.read(&car.body_color[0], color_size);

    return in;
}
std::fstream &operator<<(std::fstream &out, const Car &car)
{
    size_t reg_number_size = car.reg_number.size();
    out.write(reinterpret_cast<const char *>(&reg_number_size), sizeof(reg_number_size));
    out.write(car.reg_number.c_str(), reg_number_size);

    out.write(reinterpret_cast<const char *>(&car.year_of_release), sizeof(int));

    size_t color_size = car.body_color.size();
    out.write(reinterpret_cast<const char *>(&color_size), sizeof(color_size));
    out.write(car.body_color.c_str(), color_size);
    out.flush();
    return out;
}