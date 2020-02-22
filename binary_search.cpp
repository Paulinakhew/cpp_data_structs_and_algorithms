//
// Created by Paulina Khew on 2020-02-20.
//

int get_index_binary_search(int arr[], int left, int right, int num) {
    if (left <= right) {
        int mid = (left + right)/2;
        if (arr[mid] == num)
            return mid ;
        else if (arr[left] == num)
            return left;
        else if (arr[right] == num)
            return right;
        else if (arr[mid] > num)
            return get_index_binary_search(arr, left, mid-1, num);
        else if (arr[mid] < num)
            return get_index_binary_search(arr, mid+1, right, num);
    }
    return -1;
}
