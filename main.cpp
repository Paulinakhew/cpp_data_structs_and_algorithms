#include "linked_lists.hpp"
#include "recursive_functions.hpp"
#include "binary_search.hpp"
#include "sequential_search.hpp"

int main() {
    LinkedList* list;
    int num = 40;
    int my_arr[12] = {1, 3, 7, 15, 18, 20, 25, 33, 36, 40};
    int n = sizeof(my_arr)/ sizeof(my_arr[0]);
    int bin_search_index = get_index_binary_search(my_arr, 0, n-1, num);
    cout << "Binary search function" << endl;
    if (bin_search_index == -1)
        cout << num << " is not present in the array" << endl;
    else
        cout << num << " is present at index " << bin_search_index << " in the array" << endl;

    int seq_search_index = sequential_search(my_arr, n, num);
    cout << "Sequential search function" << endl;
    if (seq_search_index == -1)
        cout << num << " is not present in the array" << endl;
    else
        cout << num << " is present at index " << seq_search_index << " in the array" << endl;
    if (bin_search_index == seq_search_index)
        cout << "Both binary search and sequential search outputted an index of " << seq_search_index << endl;


    cout << endl << endl << endl << "Start of linked list functions" << endl;
    Node* newNode = new Node();
    newNode -> data = int(5);
    list -> head = newNode;
    Node* newerNode = new Node();
    newerNode -> data = int(25);
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

    cout << endl << endl << endl << "Start of recursive functions" << endl;
    cout << "The factorial of 4 is " << factorial(4) << endl;
    cout << "The result of converting the string '16235' into an integer is " << ascii2int("16235") << endl;
    cout << "The result of converting the integer 1234567 to a string is '" << int2ascii(1234567) << "'" << endl;
    cout << "Converting the string '10010' into decimal results in " << bin2dec("10010") << endl;
    cout << "Converting the integer 12 into a binary string results in '" << dec2bin(12) << "'" << endl;
    cout << "Printing 12345 in reverse: ";
    print_reverse_int(12345);
    cout << endl;
    cout << "Computing the sum of integers until 5: " << compute_sum_of_series(5) << endl;
    cout << "Printing the series of squares until 5: " << endl;
    print_series_of_squares(5);
    string value = (check_valid_palindrome("asdf")) ? "True" : "False";
    cout << "Is 'asdf' a valid palindrome? " << value << endl;
    value = (check_valid_palindrome("racecar")) ? "True" : "False";
    cout << "Is 'racecar' a valid palindrome? " << value << endl;
    value = (is_prime_number(11)) ? "True" : "False";
    cout << "Is 11 a prime number? " << value << endl;
    value = (is_prime_number(15)) ? "True" : "False";
    cout << "Is 15 a prime number? " << value << endl;
    cout << "Printing the individual digits of 1647 line by line: " << endl;
    print_individual_digits(1647);
    cout << "Converting integer 10 to a binary integer: " << convert_dec_to_binary(10) << endl;
    cout << "Converting integer 1010 to a decimal integer: " << convert_binary_to_dec(1010) << endl;
    cout << "The largest integer divisor of 20 is " << largest_int_divisor(20) << endl;
    cout << "The largest integer divisor of 17 is " << largest_int_divisor(17) << endl;

    return 0;
}
