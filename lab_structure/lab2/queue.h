#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

template <typename T>
class queue
{
private:
    std::int64_t capacity;

    stack<T> *left;
    stack<T> *right;

public:
    queue(std::int64_t capacity);
    queue();
    ~queue();

    void enqueue(T x);
    T dequeue();
    std::int64_t size();
    void shift();

    bool isEmpty()
    {
        return size() == -1;
    }
};

#endif