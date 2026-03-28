#ifndef STACK_H
#define STACK_H
#include "node.h"
#include <string>

template <class T>
class Stack
{
private:
    Node<T> *front;
    int nov;

public:
    Stack()
    {
        front = NULL;
        nov = 0;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void push(T data)
    {
        Node<T> *nn = new Node<T>;
        nn->setData(data);

        if (front == NULL)
        {
            front = nn;
            nov++;
            return;
        }

        nn->setNext(front);
        front = nn;
        nov++;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return T();
        }
        nov--;
        T data = front->getData();
        front = front->getNext();
        return data;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "The stack is empty" << endl;
            return T();
        }

        return front->getData();
    }

    void showAll()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Node<T> *temp = front;

        for (int i = 0; i < nov; i++)
        {
            cout << i + 1 << ": " << temp->getData() << endl;
            temp = temp->getNext();
        }
    }
};

#endif