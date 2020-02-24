//
// Created by Paulina Khew on 2020-02-20.
//

int get_index_binary_search(int arr[], int first, int last, int num) {
    int middle = (first+last)/2;
    while (first <= last)
    {
        if(arr[middle] == num)
        {
            return middle;
        }
        else if(arr[middle] < num)
        {
            first = middle + 1;

        }
        else {
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
