#include "menu.h"

void Menu::choose_operation()
{
    file.open();
    while (true)
    {
        int choose = get_int("Enter number of operation ", 1, 5);
        switch (choose)
        {
        case 1:
        {
            Car new_car;
            std::cin >> new_car;
            file.write_object(new_car);
            break;
        }
        case 2:
        {
            if (!(file.is_empty()))
                file.show();
            else
                std::cout << C_RED << "File is empty.First you need to complete point one\n" << C_WHITE;
            break;
        }
        case 3:
        {
            if (!(file.is_empty()))
            {
                std::cout << "Enter the desired year for the search ";
                int find_year = get_int("", MIN_YEAR_RELEASE, MAX_YEAR_RELEASE);
                std::cout << C_YELLOW << "The number of cars with the given year of manufacture " << C_WHITE << file.find_car_by_real_year(find_year) << std::endl;
            }
            else
                std::cout << C_RED << "File is empty. First you need to complete point one\n" << C_WHITE;
            break;
        }
        case 4:
        {
            file.open();
            break;
        }
        case 5:
            return;
        default:
            break;
        }
    }
}

void Menu::print_menu() const
{
    std::cout << C_YELLOW << "\tMenu" << C_WHITE << std::endl;
    std::cout << "1.Add a new car to the file" << std::endl;
    std::cout << "2.Show all cars from the file" << std::endl;
    std::cout << "3.Count the number of cars with a certain year of release" << std::endl;
    std::cout << "4.Clear the file contents" << std::endl;
    std::cout << "5.Exit" << std::endl;
}

void Menu::start()
{
    print_menu();
    choose_operation();
}
