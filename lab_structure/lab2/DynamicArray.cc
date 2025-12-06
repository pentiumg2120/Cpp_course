#include "DynamicArray.h"

#include <cstdint>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <limits>

template class DynamicArray<float>;

template <typename T>
DynamicArray<T>::DynamicArray()
{
    this->capacity = 8;
    this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity)
{
    // check if user is dumb
    if (capacity < 1)
    {
        throw std::invalid_argument("Capacity < 1");
    }
    this->capacity = capacity;
    this->data = new T[this->capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[this->capacity]; // (*this).data

    for (int i = 0; i <= size; ++i)
    {
        this->data[i] = other.data[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray()
{
    // deallocate if allocated
    if (this->data)
    {
        delete[] this->data;
    }
}

template <typename T>
void DynamicArray<T>::push_back(T x)
{
    // reallocate memory
    // increase capacity
    // copy data
    // dealloc old
    // assign new to old
    if (size + 1 >= capacity)
    {
        increase_capacity(capacity * 2);
    }
    data[++size] = x;
    // data[size + 1] = x;
    // ++size;
}

template <typename T>
T DynamicArray<T>::add(std::int64_t idx1, std::int64_t idx2)
{
    if (idx1 > size || idx2 > size || idx1 < 0 || idx2 < 0)
    {
        throw std::invalid_argument("idx1 or idx2 out of range");
    }
    return data[idx1] + data[idx2];
}

template <typename T>
T DynamicArray<T>::max()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Empty array");
    }
    T currentMax = std::numeric_limits<T>::lowest();
    for (int i = 0; i <= size; ++i)
    {
        if (data[i] >= currentMax)
        {
            currentMax = data[i];
        }
    }
    return currentMax;
}

template <typename T>
T DynamicArray<T>::min()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Empty array");
    }
    T currentMin = std::numeric_limits<T>::max();
    for (int i = 0; i <= size; ++i)
    {
        if (data[i] <= currentMin)
        {
            currentMin = data[i];
        }
    }
    return currentMin;
}

template <typename T>
void DynamicArray<T>::clear()
{
    if (this->data)
    {
        delete[] this->data;
        this->data = nullptr;
    }
    size = -1;
    capacity = 8;
}

template <typename T>
void DynamicArray<T>::reinitialize()
{
    clear();
    data = new T[capacity](); // init with zeros
}

template <typename T>
void DynamicArray<T>::printData()
{
    if (isEmpty())
    {
        return;
    }
    for (int i = 0; i <= size; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
T DynamicArray<T>::operator[](std::int64_t idx)
{
    if (isEmpty() || idx < 0 || idx > size)
    {
        throw std::invalid_argument("Out of range");
    }
    return data[idx]; // Мы конечно во ВШЭ, но только так, и никак иначе)
}

template <typename T>
T DynamicArray<T>::operator()()
{
    if (isEmpty())
    {
        return 0;
    }
    T sum = 0;
    for (int i = 0; i <= size; ++i)
    {
        sum += data[i];
    }
    return sum;
}

template <typename T>
void DynamicArray<T>::push_front(T val)
{
    if (size + 1 >= capacity)
    {
        std::int64_t newCapacity = capacity * 2;
        T *tempArray = new T[newCapacity];
        for (int i = 0; i < capacity; ++i)
        {
            tempArray[i + 1] = data[i];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    }
    else
    {
        data[++size] = 0;
        for (int i = size; i > 0; --i)
        {
            data[i] = data[i - 1];
        }
    }
    data[0] = val;
}

template <typename T>
T DynamicArray<T>::front()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Empty array");
    }
    return data[0];
}

template <typename T>
T DynamicArray<T>::back()
{
    if (isEmpty())
    {
        throw std::invalid_argument("Empty array");
    }
    return data[size];
}

template <typename T>
void DynamicArray<T>::insert(std::int64_t idx, T val)
{
    if (isEmpty() || idx < 0 || idx > size)
    {
        throw std::invalid_argument("Out of range");
    }
    if (size + 1 >= capacity)
    {
        std::int64_t newCapacity = capacity * 2;
        T *tempArray = new T[newCapacity];
        for (int i = 0; i < idx; ++i)
        {
            tempArray[i] = data[i];
        }
        for (int i = idx; i < capacity; ++i)
        {
            tempArray[i + 1] = data[i];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    }
    else
    {
        data[++size] = 0;
        for (int i = size; i > idx; --i)
        {
            data[i] = data[i - 1];
        }
    }
    data[idx] = val;
}

template <typename T>
void DynamicArray<T>::remove(std::int64_t idx)
{
    if (isEmpty() || idx < 0 || idx > size)
    {
        throw std::invalid_argument("Out of range");
    }
    for (int i = idx; i < size; ++i)
    {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx)
{
    if (isEmpty() || idx < -1 || idx > size)
    {
        throw std::invalid_argument("Out of range");
    }
    size = idx;
}

template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t newCapacity)
{
    if (newCapacity <= capacity)
        return;

    T *tempArray = new T[newCapacity];
    for (int i = 0; i < capacity; ++i)
    {
        tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t newCapacity)
{
    if (newCapacity <= 0)
    {
        throw std::invalid_argument("Capacity out of range");
    }

    if (newCapacity > capacity)
    {
        throw std::invalid_argument("Use increase_capacity");
    }
    if (newCapacity <= size)
        size = newCapacity - 1;
    T *tempArray = new T[newCapacity];
    for (int i = 0; i <= size; ++i)
    {
        tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}
