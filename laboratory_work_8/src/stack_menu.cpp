#include "stack_menu.h"

void StackMenu::display_type_menu() const
{
    std::cout << "|Stack Type Selection|" << std::endl;
    std::cout << "1. int" << std::endl;
    std::cout << "2. double" << std::endl;
    std::cout << "3. float" << std::endl;
    std::cout << "4. char" << std::endl;
    std::cout << "5. string" << std::endl;
    std::cout << "0. Exit" << std::endl;
}

void StackMenu::display_operations_menu() const
{
    std::cout << "|Stack Operations|" << std::endl;
    std::cout << "1. Push" << std::endl;
    std::cout << "2. Pop" << std::endl;
    std::cout << "3. Peek" << std::endl;
    std::cout << "4. Check if empty" << std::endl;
    std::cout << "5. Get size" << std::endl;
    std::cout << "6. Print stack" << std::endl;
    std::cout << "7. Clear stack" << std::endl;
    std::cout << "8. Search element" << std::endl;
    std::cout << "9. Sort stack" << std::endl;
    std::cout << "10. Reverse stack" << std::endl;
    std::cout << "0. Back to type selection" << std::endl;
}

int StackMenu::get_menu_choice(const std::string &prompt) const
{
    int choice;
    while (true)
    {
        std::cout << prompt;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cout << "Invalid input! Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}

void StackMenu::clear_input_buffer() const
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void StackMenu::run()
{
    int choice;

    do
    {
        display_type_menu();
        choice = get_menu_choice("Choose stack type: ");

        switch (choice)
        {
        case 1:
            run_operations_menu<int>();
            break;
        case 2:
            run_operations_menu<double>();
            break;
        case 3:
            run_operations_menu<float>();
            break;
        case 4:
            run_operations_menu<char>();
            break;
        case 5:
            run_operations_menu<std::string>();
            break;
        case 0:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }

        if (choice != 0)
        {
            std::cout << std::endl;
        }
    } while (choice != 0);
}
