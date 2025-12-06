#include "stack.h"

#include <iostream>
#include <stdexcept>

template class stack<float>;

template <typename T>
stack<T>::stack()
{
    this->capacity = 8;
    this->data = new DynamicArray<T>(capacity);
}

template <typename T>
stack<T>::stack(std::int64_t capacity)
{
    // check if user is dumb
    if (capacity < 1)
    {
        throw std::invalid_argument("Capacity < 1");
    }
    this->capacity = capacity;
    this->data = new DynamicArray<T>(capacity);
}

template <typename T>
stack<T>::~stack()
{
    if (this->data)
    {
        delete data;
    }
}

template <typename T>
void stack<T>::push(T x)
{
    ++size;
    if (size == capacity)
    {
        throw std::overflow_error("stack is overflowed");
    }
    data->push_back(x);
}

template <typename T>
T stack<T>::top()
{
    return data->back();
}

template <typename T>
T stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("stack is underflowed");
    }
    T last = data->back();
    --size;
    data->erase_after(data->size - 1);

    return last;
}

template <typename T>
void stack<T>::printData()
{
    data->printData();
}