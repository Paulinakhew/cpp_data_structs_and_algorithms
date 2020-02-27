//
// Created by Paulina Khew on 2020-02-20.
//

#include "binary_search.hpp"

int get_index_binary_search(vector <int> numbers, int first, int last, int num) {
    int middle = (first+last)/2;
    while (first <= last)
    {
        if(numbers[middle] == num) {
            return middle;
        } else if (numbers[last] == num) {
            return last;
        } else if (numbers[first] == num) {
            return first;
        } else if(numbers[middle] < num) {
            first = middle + 1;
        } else {
            last = middle - 1;
        }
        middle = (first + last)/2;
    }
    if(first > last)
    {
        return -1;
    }
    return 0;
}
