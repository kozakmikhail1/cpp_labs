#pragma once
#include <iostream>
#include <limits>
#include "menu.h"

int get_int(const std::string& msg, int min, int max);

template<class T>
T find_max_value(T* array, int length) {
    
    T max = array[0];
    for(int i = 1; i < length; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

template<class T>
T* get_array(const std::string& msg, int &lenght)
{
    lenght = get_int("Enter lenght array ",0,INT_MAX);
    std::cout << msg << std::endl;


    T * array = new T[lenght];
    
    for(int i = 0;i < lenght;i++)
    {
        std::cout<<"Enter " << i + 1 << " element of array" << std::endl;
        std::cin >> array[i];
        if (std::cin.good() && std::cin.peek() == '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Incorrect input, try again! " << std::endl;
            i--;
        }
    }
    return array;
}

template <class T>
void print_arr(T* arr, int length)
{
    std::cout << "\nArray\n";
    for(int i = 0;i  < length;i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

