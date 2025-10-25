#pragma once

#include "get_input.h"
#include "stack_algorithms.h"
#include <iostream>
#include <limits>
#include <string>

class StackMenu
{
  private:
    void display_type_menu() const;
    void display_operations_menu() const;
    int get_menu_choice(const std::string &prompt) const;
    void clear_input_buffer() const;

    template <typename T>
    void run_operations_menu();
    template <typename T>
    void push_operation(Stack<T> &stack) const;
    template <typename T>
    void pop_operation(Stack<T> &stack) const;
    template <typename T>
    void peek_operation(Stack<T> &stack) const;
    template <typename T>
    void search_operation(Stack<T> &stack) const;
    template <typename T>
    void sort_operation(Stack<T> &stack) const;
    template <typename T>
    void reverse_operation(Stack<T> &stack) const;

  public:
    void run();
};

template <typename T>
void StackMenu::run_operations_menu()
{
    Stack<T> stack;
    int choice;

    do
    {
        display_operations_menu();
        choice = get_menu_choice("Choose an option: ");

        switch (choice)
        {
        case 1:
            push_operation(stack);
            break;
        case 2:
            pop_operation(stack);
            break;
        case 3:
            peek_operation(stack);
            break;
        case 4:
            std::cout << "Stack is " << (stack.is_empty() ? "empty" : "not empty") << std::endl;
            break;
        case 5:
            std::cout << "Stack size: " << stack.get_size() << std::endl;
            break;
        case 6:
            if (stack.is_empty())
            {
                std::cout << "Stack is empty!" << std::endl;
            }
            else
            {
                stack.print();
            }
            break;
        case 7:
            if (stack.is_empty())
            {
                std::cout << "Stack is already empty!" << std::endl;
            }
            else
            {
                stack.clear_stack();
                std::cout << "Stack cleared." << std::endl;
            }
            break;
        case 8:
            search_operation(stack);
            break;
        case 9:
            sort_operation(stack);
            break;
        case 10:
            reverse_operation(stack);
            break;
        case 0:
            std::cout << "Returning to type selection." << std::endl;
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

template <typename T>
void StackMenu::push_operation(Stack<T> &stack) const
{
    T value = get_input<T>("Enter element to push: ");
    stack.push(value);
    std::cout << "Element pushed to stack." << std::endl;
}

template <typename T>
void StackMenu::pop_operation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else
    {
        T top_value = stack.peek();
        stack.pop();
        std::cout << "Element " << top_value << " popped from stack." << std::endl;
    }
}

template <typename T>
void StackMenu::peek_operation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else
    {
        std::cout << "Top element: " << stack.peek() << std::endl;
    }
}

template <typename T>
void StackMenu::search_operation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else
    {
        T value = get_input<T>("Enter element to search: ");
        bool found = StackAlgorithms<T>::search(stack, value);
        std::cout << "Element " << value << " " << (found ? "found" : "not found") << std::endl;
    }
}

template <typename T>
void StackMenu::sort_operation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else if (stack.get_size() == 1)
    {
        std::cout << "Stack has only one element - sorting not required." << std::endl;
    }
    else
    {
        StackAlgorithms<T>::sort(stack);
        std::cout << "Stack sorted." << std::endl;
        stack.print();
    }
}

template <typename T>
void StackMenu::reverse_operation(Stack<T> &stack) const
{
    if (stack.is_empty())
    {
        std::cout << "Stack is empty!" << std::endl;
    }
    else
    {
        StackAlgorithms<T>::reverse(stack);
        std::cout << "Stack reversed." << std::endl;
        stack.print();
    }
}
