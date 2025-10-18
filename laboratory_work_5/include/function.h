#pragma once
#include "menu.h"
#include <iostream>
#include <limits>

inline constexpr int MAX_INT = 2147483647;

int get_int(const std::string &msg, int min, int max);

template <class T> T find_max_value(T *array, int length) {

  T max = array[0];
  for (int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

template <class T> T *get_array(const std::string &msg, int &lenght) {
  lenght = get_int("Enter lenght array ", 0, MAX_INT);
  std::cout << msg << std::endl;

  auto *array = new T[lenght];
  int i = 0;
  while (i < lenght) {
    std::cout << "Enter " << i + 1 << " element of array" << std::endl;
    std::cin >> array[i];
    if (std::cin.good() && std::cin.peek() == '\n') {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      i++;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Incorrect input, try again! " << std::endl;
    }
  }
  return array;
}

template <class T> void print_arr(T *arr, int length) {
  std::cout << "\nArray\n";
  for (int i = 0; i < length; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

template <typename T> void process_array() {
  int length = 0;
  T *arr = get_array<T>("", length);
  print_arr(arr, length);
  std::cout << "max value in array = " << find_max_value(arr, length)
            << std::endl;
  delete[] arr;
}