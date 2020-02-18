#include "linked_lists.hpp"
#include "recursive_functions.hpp"

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

    cout << endl << endl << endl;
    cout << factorial(3) << endl;
    cout << ascii2int("16235") << endl;
    cout << int2ascii(1234567) << endl;
    cout << bin2dec("10010") << endl;
    cout << dec2bin(12) << endl;
    print_reverse_int(12345);
    cout << endl << compute_sum_of_series(5);
    print_series_of_squares(5);
    cout << check_valid_palindrome("asdf");
    cout << is_prime_number(11);
    print_individual_digits(12412);
    cout << convert_dec_to_binary(15) << endl;
    cout << convert_binary_to_dec(1010) << endl;
    cout << largest_int_divisor(20);

    return 0;
}
