#pragma once

#include <stdexcept>

template <typename T>
class StackIterator
{
  private:
    StackNode<T> *current_node;

  public:
    StackIterator(StackNode<T> *node);
    StackIterator &operator++();
    StackIterator operator++(int);
    T &operator*();
    bool operator==(const StackIterator &other) const;
    bool operator!=(const StackIterator &other) const;
};

template <typename T>
StackIterator<T>::StackIterator(StackNode<T> *node) : current_node(node)
{
}

template <typename T>
StackIterator<T> &StackIterator<T>::operator++()
{
    if (current_node)
    {
        current_node = current_node->get_next();
    }
    return *this;
}

template <typename T>
StackIterator<T> StackIterator<T>::operator++(int)
{
    StackIterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
T &StackIterator<T>::operator*()
{
    if (!current_node)
    {
        throw std::runtime_error("Dereferencing end iterator");
    }
    return current_node->get_data();
}

template <typename T>
bool StackIterator<T>::operator==(const StackIterator &other) const
{
    return current_node == other.current_node;
}

template <typename T>
bool StackIterator<T>::operator!=(const StackIterator &other) const
{
    return !(*this == other);
}