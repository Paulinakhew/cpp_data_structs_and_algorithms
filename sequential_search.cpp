//
// Created by Paulina Khew on 2020-02-21.
//

int sequential_search(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num)
            return i;
    }
    return -1;
}
