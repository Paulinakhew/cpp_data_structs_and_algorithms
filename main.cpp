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

int main() {
    LinkedList* list;
    Node* newNode = new Node();
    newNode -> data = int(5);
    list -> head = newNode;
    Node* newerNode = new Node();
    newerNode -> data = int(25);
    list-> InsertNode(list, newerNode);
    list -> PrintList(list);
    string val_found = (list -> FindValue(list, 25)) ? "true" : "false";
    cout << "Value 25 found in list: " << val_found << endl;
    cout << "Deleting last node" << endl;
    list -> DeleteLast(list);
    val_found = (list -> FindValue(list, 25)) ? "true" : "false";
    list -> PrintList(list);
    cout << "Value 25 found in list: " << val_found << endl;

    return 0;
}
