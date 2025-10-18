#include "menu.h"

void Menu::choose_operation()
{
    try
    {
        file.open();
        while (true)
        {
            try
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
                    file.show();
                    break;
                }
                case 3:
                {
                    std::cout << "Enter the desired year for the search ";
                    int find_year = get_int("", MIN_YEAR_RELEASE, MAX_YEAR_RELEASE);
                    std::cout << C_YELLOW << "The number of cars with the given year of manufacture " << C_WHITE << file.find_car_by_real_year(find_year) << std::endl;
                    break;
                }
                case 4:
                {
                    file.open();
                    std::cout << C_GREN << "The file was successfully cleared\n" << C_WHITE;
                    break;
                }
                case 5:
                    return;
                default:
                    break;
                }
            }
            catch(FileExceptionEmpty excp)
            {
                std::cout << C_RED << excp.what() << C_WHITE << std::endl; 
            }
        }
    }
    catch(FileException excp)
    {
        std::cout << C_RED << excp.what() << C_WHITE << std::endl; 
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
