#pragma once

#include "stack.h"

template <typename T>
class StackAlgorithms
{
  public:
    static bool search(const Stack<T> &stack, const T &value);
    static void sort(Stack<T> &stack);
    static void reverse(Stack<T> &stack);
};

template <typename T>
bool StackAlgorithms<T>::search(const Stack<T> &stack, const T &value)
{
    for (auto it = stack.begin(); it != stack.end(); ++it)
    {
        if (*it == value)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
void StackAlgorithms<T>::sort(Stack<T> &stack)
{
    if (stack.is_empty() || stack.get_size() == 1)
    {
        return;
    }

    bool swapped;
    size_t n = stack.get_size();

    do
    {
        swapped = false;
        Stack<T> temp;
        T current = stack.peek();
        stack.pop();

        for (int i = 1; i < n; i++)
        {
            T next = stack.peek();
            stack.pop();

            if (current > next)
            {
                temp.push(next);
                swapped = true;
            }
            else
            {
                temp.push(current);
                current = next;
            }
        }
        temp.push(current);

        while (!temp.is_empty())
        {
            stack.push(temp.peek());
            temp.pop();
        }
        n--;
    } while (swapped);
}

template <typename T>
void StackAlgorithms<T>::reverse(Stack<T> &stack)
{
    if (stack.is_empty() || stack.get_size() == 1)
    {
        return;
    }

    Stack<T> temp;

    while (!stack.is_empty())
    {
        temp.push(stack.peek());
        stack.pop();
    }

    stack = temp;
}
