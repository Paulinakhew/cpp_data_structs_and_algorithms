//
// Created by Paulina Khew on 2020-02-21.
//

#include "sequential_search.hpp"

int sequential_search(vector <int> numbers, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (numbers[i] == num)
            return i;
    }
    return -1;
}
