#include "DynamicArray.h"
#include "stack.h"
#include "queue.h"
#include <iostream>

int main()
{
    DynamicArray<float> arr;
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.printData();
    std::cout << arr.min() << " " << arr.size << std::endl;
    std::cout << arr.max() << std::endl;
    std::cout << arr.add(0, 2) << std::endl;
    // arr.clear();
    arr.printData();
    std::cout << arr[0] << std::endl;
    // std::cout << arr.operator[](2) << std::endl;
    // std::cout << arr() << std::endl;

    std::cout << std::endl;
    arr.printData();
    arr.push_front(-1);
    arr.push_front(-2);
    arr.printData();
    std::cout << "Front: " << arr.front() << " | Back: " << arr.back() << std::endl;
    arr.insert(0, -2.5);
    arr.insert(5, 4.5);
    arr.printData();
    arr.remove(5);
    arr.remove(0);
    arr.printData();
    arr.erase_after(2);
    arr.printData();
    arr.decrease_capacity(1);
    arr.printData();

    // stack<float> hehe;
    // hehe.push(1);
    // hehe.push(2);
    // hehe.push(3);
    // std::cout << hehe.top() << std::endl;
    // hehe.push(42.4242);
    // hehe.printData();
    // std::cout << hehe.pop() << std::endl;
    // hehe.printData();
    // hehe.push(1);
    // hehe.push(2);
    // hehe.push(3);
    // hehe.push(1);
    // hehe.printData();
    // hehe.push(2);
    // hehe.printData();
    // // hehe.push(3);
    // // hehe.push(2);

    // queue<float> klekle;
    // klekle.enqueue(1.1);
    // std::cout << klekle.dequeue() << std::endl;
    // klekle.enqueue(2.2);
    // klekle.enqueue(3.3);
    // klekle.enqueue(4.4);
    // std::cout << klekle.dequeue() << std::endl;
    // std::cout << klekle.dequeue() << std::endl;
    // std::cout << klekle.dequeue() << std::endl;
    // // std::cout << klekle.dequeue() << std::endl;

    return 0;
}