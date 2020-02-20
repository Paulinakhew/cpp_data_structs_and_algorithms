#include "linked_lists.hpp"
#include "recursive_functions.hpp"

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
    cout << "Length of linked list: " << list -> GetLength(list) << endl;
    cout << "Value 25 found in list: " << val_found << endl;
    cout << "Index of 25 in list: " << list -> GetIndex(list, 25) << endl;
    cout << "Deleting last node" << endl;
    list -> DeleteLast(list);
    cout << "Length of linked list: " << list -> GetLength(list) << endl;
    val_found = (list -> FindValue(list, 25)) ? "true" : "false";
    list -> PrintList(list);
    cout << "Value 25 found in list: " << val_found << endl;

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
