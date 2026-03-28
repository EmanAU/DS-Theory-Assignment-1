#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

const int SIZE = 100;

template <class T>
class Stack
{
private:
    T arr[SIZE];
    int current;

public:
    Stack()
    {
        current = 0;
    }

    bool isEmpty()
    {
        return (current == 0);
    }

    bool isFull()
    {
        return (current == SIZE);
    }

    void push(T value)
    {
        if (isFull())
        {
            cout << "Stack is full, can't push the value" << endl;
            return;
        }
        arr[current++] = value;
    }

    T pop()
    {
        return arr[--current];
    }

    T top()
    {
        return arr[current - 1];
    }
};

#endif