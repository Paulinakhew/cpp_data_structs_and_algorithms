//
// Created by Paulina Khew on 2020-02-19.
//

#include "linked_lists.hpp"


Node::Node() : data(0), next(nullptr) {}

Node::Node(int new_data) : data(new_data), next(nullptr) {}

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::~LinkedList() {

}

void LinkedList::InsertNode(LinkedList* list, struct Node* newNode) {
    // If the list is empty, create a new head node
    newNode -> next = nullptr;
    if (list->head == nullptr){
        list -> head = newNode;
    }
        // If the list is not empty, start at the head
        // and follow the links until you find the end of the list
    else {
        Node * temp = list -> head;
        while (temp -> next != nullptr) {
            temp = temp -> next;
        }

        // Then, set the end of the list to point to the new node
        temp -> next = newNode;
    }
}

void LinkedList::PrintList(LinkedList* list) {
    if (list == nullptr)
        return;
    cout << "(";
    Node* node = list -> head;
    while (node != nullptr) {
        cout << "[" << node -> data << "]";
        node = node -> next;
        if (node != nullptr)
            cout << "->";
    }
    cout << ")\n";
}

bool LinkedList::FindValue(LinkedList* list, int value) {
    if (list == nullptr)
        return false;
    Node* node = list -> head;
    while (node != nullptr) {
        if (node -> data == value)
            return true;
        node = node -> next;
    }
    return false;
}

int LinkedList::GetIndex(LinkedList* list, int value) {
    if (list == nullptr)
        return -1;
    Node* node = list -> head;
    int index = 0;
    while (node!= nullptr) {
        if (node -> data == value)
            return index;
        index++;
        node = node -> next;
    }
    return -1;
}

void LinkedList::DeleteLast(LinkedList* list) {
    if (list == nullptr)
        return;

    // Check to make sure that there are at least two elements in the list
    if (list -> head != nullptr && list -> head -> next != nullptr) {
        // When this loop finishes, newLast will point to the node
        // that will be second-last in the list.
        Node* newLast = list -> head;
        while (newLast -> next -> next != nullptr) {
            newLast = newLast -> next;
        }
        delete newLast -> next;
        newLast -> next = nullptr;

        // If there is only 1 Node in the list, we just have to delete that node,
        // and set head to NULL
    } else if (list -> head != nullptr) {
        delete list -> head;
        list -> head = nullptr;
    }

    // The only remaining case is that the list was empty
    // to begin with, in which case we should do nothing
}

int LinkedList::GetLength(LinkedList* list) {
    int counter = 0;
    if (list == NULL) {
        return 0;
    } else {
        Node* iterate = list -> head;
        while (iterate) {
            counter ++;
            iterate = iterate -> next;
        }
    }
    return counter;
}