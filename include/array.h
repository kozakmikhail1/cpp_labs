#pragma once
#include <iostream>
#include "functions.h"

class Array
{
    int size;
    int *data;
 
    public :

    Array();
    explicit Array(int size);
    Array(const Array &other_arr);
    Array(Array &&) noexcept;
    ~Array();

    Array & operator !(); 
    Array & operator = (Array &&other) noexcept;
    Array & operator = (const Array& other);


    friend void show (const Array& arr, std::string message);
    friend void enter(Array& arr);

    int get_size() const;
    bool is_empty() const;

};