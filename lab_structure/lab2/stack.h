#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"

template <typename T>
class stack
{
private:
    std::int64_t capacity;

    DynamicArray<T> *data;

public:
    std::int64_t size = -1;

    stack(std::int64_t capacity);
    stack();
    ~stack();

    void push(T x);
    T top();
    T pop();
    void printData();

    bool isEmpty()
    {
        return size == -1;
    }
};

#endif