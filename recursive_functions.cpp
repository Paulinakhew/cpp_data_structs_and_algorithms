//
// Created by Paulina Khew on 2020-02-18.
//

#include "recursive_functions.hpp"


void print_reverse_int(int my_number) {
    int last_idx = to_string(my_number).length() - 1;
    if (my_number) {
        cout << to_string(my_number)[last_idx];
        my_number = my_number / 10;
        print_reverse_int(my_number);
    }
}

void print_individual_digits(int n) {
    int last_idx = to_string(n).length() - 1;
    if (n) {
        print_individual_digits(n / 10);
        cout << to_string(n)[last_idx] << endl;
    }
}

int compute_sum_of_series(int n) {
    if (n == 1)
        return 1;
    else {
        return n + compute_sum_of_series(n-1);
    }
}

void print_series_of_squares(int n) {
    if (n == 1)
        cout << 1 << endl;
    else {
        print_series_of_squares(n - 1);
        cout << pow(n, 2) << endl;
    }
}

int largest_int_divisor(int number) {  // helper function
    return largest_int_divisor(number, number/2);
}

int largest_int_divisor(int number, int divisor) {
    if (divisor == 1){
        return 1;
    }
    else {
        if (number % divisor == 0){
            return divisor;
        }
        return largest_int_divisor(number, divisor - 1);
    }
}

bool check_valid_palindrome(string my_string) {
    if (my_string.length() == 0)
        return true;
    else if (my_string.length() == 1)
        return true;
    else {
        int last_idx = my_string.length() - 1;
        if (my_string[0] == my_string[last_idx]) {
            return check_valid_palindrome(my_string.substr(1, last_idx-1));
        }
    }
}

bool is_prime_number(int n) {  // helper function
    if (n > 1)
        return is_prime_number(n, n/2);
    else
        return false;
}

bool is_prime_number(int n, int divisor) {
    if (divisor == 1)
        return true;
    else {
        if (n % divisor == 0)
            return false;
        else
            return is_prime_number(n, divisor - 1);
    }
}

int factorial(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return n * factorial(n-1);
    }
}

int convert_dec_to_binary(int decimal) {
    if (decimal == 0)
        return 0;
    else
        return (decimal % 2 + 10 * convert_dec_to_binary(decimal / 2));
}

int convert_binary_to_dec(int binary) {
    if (binary == 0)
        return 0;
    else
        return (binary % 10 + 2 * convert_binary_to_dec(binary / 10));
}

int bin2dec(string binary) {
    int last_num;
    if (binary == "")
        return 0;
    else {
        last_num =  binary[binary.size() - 1] - '0';
        return last_num + 2 * (bin2dec(binary.substr(0, binary.size()-1)));
    }
}

string dec2bin(int decimal) {
    if (!decimal)
        return "";
    else {
        string last_num = to_string(decimal % 2);
        return dec2bin(decimal / 2) + last_num;
    }
}

int ascii2int(string digits) {
    if (digits.size() == 0)
        return 0;
    int x = digits[digits.size()-1] - '0';
    if (digits.size() == 1) {
        return x;
    }
    else {
        return x + 10 * (ascii2int(digits.substr(0, digits.size()-1)));
    }
}

string int2ascii(int my_int) {
    if (my_int < 10)
        return to_string(my_int);
    int last_number = my_int % 10;

    return int2ascii(my_int / 10) + to_string(last_number);
}

vector<int> recursive_selection_sort(vector<int> numbers, int n) {
    int max_position, temp;
    if (n > 0) {
        max_position = find_max(numbers, n);
        temp = numbers[n];
        numbers[n] = numbers[max_position];
        numbers[max_position] = temp;
        return recursive_selection_sort(numbers, n - 1);
    } else {
        return numbers;
    }
}

int find_max(vector<int> numbers, int n) {
    int j = n;
    for (int i = 0; i < n; i++) {
        if (numbers[i] > numbers[j]) {
            j = i;
        }
    }
    return j;
}