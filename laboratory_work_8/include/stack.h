#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value);
    };

    Node *top_node;
    size_t stack_size;

public:
    Stack();
    ~Stack();
    Stack(const Stack &other);
    Stack &operator=(const Stack &other);

    void push(const T &value);
    void pop();
    T peek() const;
    bool is_empty() const;
    size_t get_size() const;
    void print() const;
    void clear_stack();

    class Iterator
    {
    private:
        Node *current;

    public:
        Iterator(Node *node);
        T &operator*() const;
        Iterator &operator++();
        bool operator!=(const Iterator &other) const;
        bool operator==(const Iterator &other) const;
    };

    Iterator begin() const;
    Iterator end() const;
};

template <typename T>
Stack<T>::Node::Node(const T &value) : data(value), next(nullptr) {}

template <typename T>
Stack<T>::Stack() : top_node(nullptr), stack_size(0) {}

template <typename T>
Stack<T>::~Stack()
{
    clear_stack();
}

template <typename T>
Stack<T>::Stack(const Stack &other) : top_node(nullptr), stack_size(0)
{
    Stack<T> temp;
    Node *current = other.top_node;
    while (current)
    {
        temp.push(current->data);
        current = current->next;
    }
    while (!temp.is_empty())
    {
        push(temp.peek());
        temp.pop();
    }
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack &other)
{
    if (this != &other)
    {
        clear_stack();
        Stack<T> temp;
        Node *current = other.top_node;
        while (current)
        {
            temp.push(current->data);
            current = current->next;
        }
        while (!temp.is_empty())
        {
            push(temp.peek());
            temp.pop();
        }
    }
    return *this;
}

template <typename T>
void Stack<T>::push(const T &value)
{
    Node *new_node = new Node(value);
    new_node->next = top_node;
    top_node = new_node;
    stack_size++;
}

template <typename T>
void Stack<T>::pop()
{
    if (is_empty())
    {
        throw std::runtime_error("Stack is empty");
    }
    Node *temp = top_node;
    top_node = top_node->next;
    delete temp;
    stack_size--;
}

template <typename T>
T Stack<T>::peek() const
{
    if (is_empty())
    {
        throw std::runtime_error("Stack is empty");
    }
    return top_node->data;
}

template <typename T>
bool Stack<T>::is_empty() const
{
    return top_node == nullptr;
}

template <typename T>
size_t Stack<T>::get_size() const
{
    return stack_size;
}

template <typename T>
void Stack<T>::print() const
{
    if (is_empty())
    {
        std::cout << "Stack is empty" << std::endl;
        return;
    }
    std::cout << "Stack elements (top to bottom): ";
    Node *current = top_node;
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void Stack<T>::clear_stack()
{
    while (!is_empty())
    {
        pop();
    }
}

template <typename T>
Stack<T>::Iterator::Iterator(Node *node) : current(node) {}

template <typename T>
T &Stack<T>::Iterator::operator*() const
{
    return current->data;
}

template <typename T>
typename Stack<T>::Iterator &Stack<T>::Iterator::operator++()
{
    if (current)
    {
        current = current->next;
    }
    return *this;
}

template <typename T>
bool Stack<T>::Iterator::operator!=(const Iterator &other) const
{
    return current != other.current;
}

template <typename T>
bool Stack<T>::Iterator::operator==(const Iterator &other) const
{
    return current == other.current;
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::begin() const
{
    return Iterator(top_node);
}

template <typename T>
typename Stack<T>::Iterator Stack<T>::end() const
{
    return Iterator(nullptr);
}