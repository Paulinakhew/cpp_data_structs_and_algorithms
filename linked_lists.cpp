//
// Created by Paulina Khew on 2020-02-19.
//

#include "linked_lists.hpp"


void LinkedList::InsertNode(LinkedList* list, struct Node* newNode) {
    // If the list is empty, create a new head node
    if (list->head == NULL){
        list -> head = newNode;
        newNode -> next = NULL;
    }
        // If the list is not empty, start at the head
        // and follow the links until you find the end of the list
    else {
        Node * end = list -> head;
        while (end -> next != NULL) {
            end = end -> next;
        }

        // Then, set the end of the list to point to the new node
        end -> next = newNode;
        newNode -> next = NULL;
    }
}

void LinkedList::PrintList(LinkedList* list) {
    if (list == NULL)
        return;
    cout << "(";
    Node* node = list -> head;
    while (node != NULL) {
        cout << "[" << node -> data << "]";
        node = node -> next;
        if (node != NULL)
            cout << "->";
    }
    cout << ")\n";
}

bool LinkedList::FindValue (LinkedList* list, int value) {
    if (list == NULL)
        return false;
    Node* node = list -> head;
    while (node != NULL) {
        if (node -> data == value)
            return true;
        node = node -> next;
    }
    return false;
}

int LinkedList::GetIndex (LinkedList* list, int value) {
    if (list == NULL)
        return -1;
    Node* node = list -> head;
    int index = 0;
    while (node!= NULL) {
        if (node -> data == value)
            return index;
        index++;
        node = node -> next;
    }
    return -1;
}

void LinkedList::DeleteLast(LinkedList* list) {
    if (list == NULL)
        return;

    // Check to make sure that there are at least two elements in the list
    if (list -> head != NULL && list -> head -> next != NULL) {
        // When this loop finishes, newLast will point to the node
        // that will be second-last in the list.
        Node* newLast = list -> head;
        while (newLast -> next -> next != NULL) {
            newLast = newLast -> next;
        }
        delete newLast -> next;
        newLast -> next = NULL;

        // If there is only 1 Node in the list, we just have to delete that node,
        // and set head to NULL
    } else if (list -> head != NULL) {
        delete list -> head;
        list -> head = NULL;
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