#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T>
class DynamicArray
{
private:
    T *data;
    std::int64_t capacity;

public:
    std::int64_t size = -1;

    DynamicArray();
    DynamicArray(std::int64_t capacity);
    DynamicArray(DynamicArray &other);
    ~DynamicArray();

    void push_back(T x);
    T add(std::int64_t idx1, std::int64_t idx2);
    T max();
    T min();
    void clear();
    void reinitialize();
    void printData();
    T operator[](std::int64_t idx);
    T operator()();

    void push_front(T val);
    T front();
    T back();
    void insert(std::int64_t idx, T val);
    void remove(std::int64_t idx);
    void erase_after(std::int64_t idx);
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);

    bool isEmpty()
    {
        return size == -1;
    }
};

#endif
