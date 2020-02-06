#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
public:
    void InsertNode(LinkedList* list, struct Node* newNode) {
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

    void PrintList(LinkedList* list) {
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
};

int main() {
    LinkedList* list;
    Node* newNode = new Node();
    newNode -> data = int(5);
    list -> head = newNode;
    Node* newerNode = new Node();
    newerNode -> data = int(25);
    list-> InsertNode(list, newerNode);
    list -> PrintList(list);
    return 0;
}
