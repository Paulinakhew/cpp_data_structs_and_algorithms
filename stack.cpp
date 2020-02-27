//
// Created by Paulina Khew on 2020-02-26.
//

#include "stack.h"

stack::stack(int size) {  // constructor to initialize stack
    arr = new int[size];
    capacity = size;
    top = -1;
}

stack::~stack() {  // destructor function to free memory allocated to the stack
    delete arr;
}

void stack::push(int x) {  // add element x into the stack
    if (isFull()) {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

int stack::pop() {  // remove top element from the stack
    if (isEmpty()) {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    return arr[top--];
}

int stack::peek() {  // return top element in a stack
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

int stack::size() {  // return the size of a stack
    return top + 1;
}

bool stack::isEmpty() {  // check if the stack is empty or not
    return top == -1; // or return size() == 0;
}

bool stack::isFull() {
    return top == capacity - 1; // or return size() == capacity
}