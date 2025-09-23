#include "array.h"

Array::Array() : Array (3){}

Array::Array(int size): size(size), data(nullptr)
{
    auto * temp = new int[size]{};
    data = temp;
}

Array::Array(const Array& other_arr) : size(other_arr.size), data(new int[other_arr.size]) 
{
    for (size_t i = 0; i < size; ++i) {
        data[i] = other_arr.data[i];
    }
}

Array::Array(Array && other)noexcept : size(other.size), data(other.data)
{
    other.size = 0;
    other.data = nullptr;
}


Array::~Array()
{
    delete[] data;
    data = nullptr;
    size = 0;
}


Array &  Array :: operator !()
{
    auto * temp = new int[size * 2];
    for(int i = 0;i < size;i++)
    {
        temp[i] = data[i];
        temp[i + size] = data[i];
    }
    delete[] data;
    data = temp;
    size *= 2;

    return *this;
}

Array& Array::operator=(Array&& other) noexcept 
{
    if (this != &other) {
        delete[] data;     
        
        data = other.data; 
        size = other.size;
        
        other.data = nullptr;  
        other.size = 0;
    }
    return *this;
}

Array & Array::operator = (const Array &other)
{
    size = other.size;
    for(int i = 0;i < size;i++)
    {
        this->data[i] = other.data[i];
    }
    return *this;
}

int Array::get_size() const {  return size;  };

bool Array::is_empty() const
{
    return data == nullptr;
}

void show(const Array & arr, const std::string message)
{
    if(arr.data != nullptr)
    {
        std::cout << message << std::endl;
        for(int i = 0;i < arr.size;i++)
        {
            std::cout << arr.data[i] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void enter(Array &arr)
{
    if(arr.size != 0)
    {
        for(int i = 0;i < arr.size;i++)
        {
            std::cout << "Enter one value for the array [" << i + 1 << "]"<<std::endl;
            arr.data[i] = input_int("");
        }
    }
}