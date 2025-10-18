#include "menu.h"

void print_menu_construct()
{
    std::cout << "You must select a constructor to create the array: " << std::endl;
    std::cout << "1.Basic Constructor." << std::endl;
    std::cout << "2.Constructor with parameters." << std::endl;
    std::cout << "3.Exit. " << std::endl;
}

void print_menu_operations()
{
    std::cout << "\tMenu" << std::endl;
    std::cout << "1.Entering values for an equation " << std::endl;
    std::cout << "2.Displaying an equation on the screen" << std::endl;
    std::cout << "3.Find the roots of the quadratic equation." << std::endl;
    std::cout << "4.Exit" << std::endl;
}

void Menu::choose_operations()
{
    while (true)
    {
        try
        {
            print_menu_operations();
            int choose = input_int("Enter number of operation ");
            switch (choose)
            {
            case 1:
                equation->enter_value();
                break;
            case 2:
                equation->show_equation();
                break;
            case 3:
                equation->find_root();
                equation->show_root();
                break;
            case 4:
                return;
            default:
                std::cout << C_RED << "You make mistake" << C_WHITE << std::endl;
                break;
            }
        }
        catch(BadArgument exc)
        {
            std::cout << C_RED << exc.what() << C_WHITE << std::endl;
        }
    }
}
void Menu::choose_construct()
{
    int choose = 0;

    while (true)
    {
        try
        {
            print_menu_construct();
            choose = input_int("Enter number of operation ");
            switch (choose)
            {
            case 1:
                equation = new C();
                return;
            case 2:
                equation = new C(input_int("Enter a "), input_int("Enter b "), input_int("Enter c "));
                return;
            case 3:
                delete equation;
                equation = nullptr;
                return;
            default:
                std::cout << C_RED << "You make mistake" << C_WHITE << std::endl;
                break;
            }
        }
        catch(BadArgument exc)
        {
            std::cout << C_RED << exc.what() << C_WHITE << std::endl;
        }
    }
}

void Menu::start()
{
    system("clear");
    choose_construct();
    if (equation != nullptr)
        choose_operations();
}