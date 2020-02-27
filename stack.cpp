//
// Created by Paulina Khew on 2020-02-26.
//

#include "stack.hpp"

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

void stack::removeMaxFromStack() {  // remove maximum value from stack
    if (isEmpty()) {
        cout << "Stack is empty\nCannot remove max number";
        exit(EXIT_FAILURE);
    }
    stack new_stack = stack(10);
    int max = arr[top];
    while (!isEmpty()) {
        int cur = arr[top];
        if (max < cur) // update max value
            max = cur;
        cout << "Adding to the new stack: ";
        new_stack.push(cur);
        cout << "Removing from original stack: ";
        pop();
    }
    while (!new_stack.isEmpty()) { // put numbers back in original stack
        int cur = new_stack.peek();
        if (cur < max) {
            cout << "Re-adding numbers to original stack: ";
            push(cur);
        }
        cout << "Removing from the new stack: ";
        new_stack.pop();
    }
}

void stack::printStack() {
    int num = size();
    cout << "This is the current stack: [ ";
    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}
