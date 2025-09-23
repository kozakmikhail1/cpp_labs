#include "menu.h"


void print_menu_constructor()
{
    std::cout << "You must select a constructor to create the array: "<< std::endl;
    std::cout << "1.Basic Constructor."<< std::endl;
    std::cout << "2.Constructor with input of array length."<< std::endl;
    std::cout << "3.Exit"<< std::endl;

}

void print_menu()
{
    std::cout << "\tMenu"<< std::endl;
    std::cout << "1.Entering values for an array "<< std::endl;
    std::cout << "2.Displaying an array on the screen"<< std::endl;
    std::cout << "3.Using an overloaded operation '!' for array"<< std::endl;
    std::cout << "4.Exit"<< std::endl;
}

void Menu::choose_operation()
{
    while(true)
    {
        print_menu();
        int choose = input_int("Enter number of operation ");
        switch (choose)
        {
        case 1:
            enter(arr_1);
            break;
        case 2:
            show(arr_1,"\nArray ");
            std::cout <<" " << std::endl;
            break;
        case 3:
            arr_1 = std::move(!arr_1);
            break;
        case 4:
            return;
        default:
            std::cout <<C_RED <<"You make mistake"<<C_WHITE<<std::endl;
            break;
        }
    }
}
void Menu::choose_constructor()
{
    int choose = 0;

    while(true)
    {
        print_menu_constructor();
        choose = input_int("Enter number of operation ");
        switch (choose)
        {
            case 1:
            {
                choose_operation();
                break;
            }
            case 2:
            {
                Array temp_arr_(input_int("Enter size of array "));
                arr_1 = std::move(temp_arr_);
                choose_operation();
                break;
            }
            case 3:
            {
                return;
            }
            default:
                std::cout << C_RED << "You make mistake"<< C_WHITE <<std::endl;
                break;
        }
    }
}


void Menu::start()
{
    system("clear");
    choose_constructor();
}