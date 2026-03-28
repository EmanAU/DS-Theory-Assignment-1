#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *next;

public:
    Node()
    {
        data = T();
        next = NULL;
    }

    void setNext(Node *nxt) { next = nxt; }
    void setData(T d) { data = d; }

    Node *getNext() { return next; }
    T getData() { return data; }
};

#endif