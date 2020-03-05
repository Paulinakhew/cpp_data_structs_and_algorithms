//
// Created by Paulina Khew on 2020-02-28.
//

#ifndef CPP_LINKED_LISTS_TEST_FUNCTIONS_HPP
#define CPP_LINKED_LISTS_TEST_FUNCTIONS_HPP

#include "linked_lists.hpp"
#include "recursive_functions.hpp"
#include "binary_search.hpp"
#include "sequential_search.hpp"
#include "stack.hpp"
#include "selection_sort.hpp"
#include <vector>

using namespace std;

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class TestDataStructsandAlgorithms {
public:
    bool test_recursive_functions() {
        cout << endl << endl << endl << "Start of recursive functions" << endl;
        cout << "Printing 12345 in reverse: ";
        print_reverse_int(12345);
        cout << endl;

        cout << "Printing the individual digits of 1647 line by line: " << endl;
        print_individual_digits(1647);
        cout << endl;

        assert(compute_sum_of_series(5) == 15);

        cout << "Printing the series of squares until 10: " << endl;
        print_series_of_squares(10);

        assert(largest_int_divisor(20) == 10);
        assert(largest_int_divisor(30) == 15);
        assert(largest_int_divisor(7) == 1);
        assert(largest_int_divisor(17) == 1);

        assert(check_valid_palindrome("asdffdsa"));
        ASSERT_FALSE(check_valid_palindrome("asdf"));
        assert(check_valid_palindrome("racecar"));

        ASSERT_FALSE(is_prime_number(15));
        ASSERT_TRUE(is_prime_number(11));
        ASSERT_FALSE(is_prime_number(1));
        ASSERT_FALSE(is_prime_number(0));
        ASSERT_FALSE(is_prime_number(-7));

        assert(factorial(4) == 24);
        assert(factorial(5) == 120);

        assert(convert_dec_to_binary(10) == 1010);

        assert(convert_binary_to_dec(1010) == 10);

        assert(bin2dec("10010") == 18);

        assert(dec2bin(12) == "1100");

        assert(ascii2int("16235") == 16235);

        assert(int2ascii(1234567) == "1234567");

        return true;
    }

    bool test_stack_implementation() {
        stack pt(3);
        pt.push(1);
        pt.push(2);
        pt.pop();
        pt.pop();
        pt.push(3);

        assert(pt.peek() == 3);
        assert(pt.size() == 1);

        pt.pop();

        assert(pt.isEmpty());

        pt.push(1);
        pt.push(25);
        pt.push(2);

        pt.removeMaxFromStack();
        pt.printStack();
        assert(pt.peek() == 2);
        pt.pop();
        assert(pt.peek() == 1);
        pt.pop();
        assert(pt.isEmpty());

        return true;
    }

    bool test_sort_algorithms() {
        vector<int> unsorted = {4, 9, 28, 46, 1, 7, 232, 801};
        vector<int> sorted = selection_sort(unsorted);
        vector<int> sorted_2 = recursive_selection_sort(unsorted, unsorted.size() - 1);
        assert(sorted == sorted_2);
        return true;
    }

    bool test_linked_list() {
        return false;
    }

    bool test_search_functions() {
        return false;
    }
};

#endif //CPP_LINKED_LISTS_TEST_FUNCTIONS_HPP
