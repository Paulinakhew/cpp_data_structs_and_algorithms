#include "linked_lists.hpp"
#include "test_functions.hpp"
#include <array>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef high_resolution_clock Clock;
typedef Clock::time_point ClockTime;

string get_status_str(bool status) {
    return status ? "TEST PASSED" : "TEST FAILED";
}

int main() {
    TestDataStructsandAlgorithms test_data_structs_and_algos;
    LinkedList* list;

    cout << endl << endl << endl << "Start of linked list functions" << endl;
    Node* newNode = new Node(5);
    list -> InsertNode(list, newNode);
    Node* newerNode = new Node(25);
    list-> InsertNode(list, newerNode);
    Node* last = new Node(123);
    list-> InsertNode(list, last);
    list -> PrintList(list);
    string val_found = (list -> FindValue(list, 123)) ? "true" : "false";
    cout << "Length of linked list: " << list -> GetLength(list) << endl;
    cout << "Value 123 found in list: " << val_found << endl;
    cout << "Index of 25 in list: " << list -> GetIndex(list, 25) << endl;
    cout << "Deleting last node" << endl;
    list -> DeleteLast(list);
    cout << "Length of linked list: " << list -> GetLength(list) << endl;
    val_found = (list -> FindValue(list, 123)) ? "true" : "false";
    list -> PrintList(list);
    cout << "Value 123 found in list: " << val_found << endl;

    array<string, 5> test_descriptions = {
            "Test 1: recursive functions return the proper output",
            "Test 2: check stack implementation",
            "Test 3: test sort algorithms return the same vectors",
            "Test 4: initialize and test various linked list functions",
            "Test 5: use search functions to find index of a value"
    };

    bool test_results[5] = {false};
    test_results[0] = test_data_structs_and_algos.test_recursive_functions();
    test_results[1] = test_data_structs_and_algos.test_stack_implementation();
    test_results[2] = test_data_structs_and_algos.test_sort_algorithms();
    test_results[3] = test_data_structs_and_algos.test_linked_list();
    test_results[4] = test_data_structs_and_algos.test_search_functions();

    cout << "\n\n\n\n\nTEST RESULTS \n";
    cout << "*************************** \n";
    for (int index = 0; index < 5; ++index) {
        cout << test_descriptions[index] << endl << get_status_str(test_results[index]) << endl;
    }

    return 0;
}
