//
// Created by Paulina Khew on 2020-02-29.
//

#include "selection_sort.hpp"


vector<int> selection_sort(vector<int> numbers) {
    int max_position, temporary, size;
    size = numbers.size();
    for (int i = size-1; i > 0; --i) {
        max_position = i;
        for (int j = 0; j < i; ++j) {
            if (numbers[j] > numbers[max_position])
                max_position = j;
        }
        temporary = numbers[i];
        numbers[i] = numbers[max_position];
        numbers[max_position] = temporary;
    }
    return numbers;
}