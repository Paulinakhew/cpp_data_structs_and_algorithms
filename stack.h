//
// Created by Paulina Khew on 2020-02-26.
//

#ifndef CPP_LINKED_LISTS_STACK_H
#define CPP_LINKED_LISTS_STACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

#define SIZE 10

class stack {
    int *arr;
    int top, capacity;

public:
    explicit stack(int size = SIZE);
    ~stack();

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();

    void removeMaxFromStack();
    void printStack();
};

#endif //CPP_LINKED_LISTS_STACK_H
