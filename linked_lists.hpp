//
// Created by Paulina Khew on 2020-02-18.
//

#ifndef CPP_LINKED_LISTS_LINKED_LISTS_HPP
#define CPP_LINKED_LISTS_LINKED_LISTS_HPP

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;

public:
    void InsertNode(LinkedList* list, struct Node* newNode);
    void PrintList(LinkedList* list);
    bool FindValue (LinkedList* list, int value);
    void DeleteLast(LinkedList* list);
    int GetLength(LinkedList* list);
    };


#endif //CPP_LINKED_LISTS_LINKED_LISTS_HPP
