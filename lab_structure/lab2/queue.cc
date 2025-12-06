#include "queue.h"

#include <iostream>
#include <stdexcept>

template class queue<float>;

template <typename T>
queue<T>::queue()
{
    this->capacity = 8;
    this->left = new stack<T>(8);
    this->right = new stack<T>(8);
}

template <typename T>
queue<T>::queue(std::int64_t capacity)
{
    // check if user is dumb
    if (capacity < 1)
    {
        throw std::invalid_argument("Capacity < 1");
    }
    this->capacity = capacity;

    this->left = new stack<T>(capacity);
    this->right = new stack<T>(capacity);
}

template <typename T>
queue<T>::~queue()
{
    if (this->left)
    {
        delete left;
    }
    if (this->right)
    {
        delete right;
    }
}

template <typename T>
void queue<T>::shift()
{
    if (!left->isEmpty())
    {
        throw std::logic_error("Left stack not empty");
    }
    while (!right->isEmpty())
    {
        left->push(right->pop());
    }
}

template <typename T>
std::int64_t queue<T>::size()
{
    return left->size + right->size + 2; // т.к. это функция, возвращаяем в человекочитаемом виде
}

template <typename T>
void queue<T>::enqueue(T x)
{
    if (size() == capacity)
    {
        throw std::overflow_error("queue is overflowed");
    }
    right->push(x);
}

template <typename T>
T queue<T>::dequeue()
{
    if (left->isEmpty())
    {
        if (right->isEmpty())
        {
            throw std::underflow_error("queue is underflowed");
        }
        else
        {
            shift();
        }
    }
    return left->pop();
}