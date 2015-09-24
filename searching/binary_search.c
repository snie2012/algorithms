#include <stdio.h>
#include <stdlib.h>

int binary_search_recursive(int *arr, int n, int s) {
    if (n == 0) return -1;
    int i = n/2;
    if (s == arr[i]) {
        return i;
    } else if (s > arr[i]) {
        // We have to check the returned result of the upper splitted half, if it does find the searching value,
        // the returned index has to be incremented to index+i+1 because the return index is relative to the splitted array
        // but not relative to the original array.
        int result = binary_search_recursive(arr+i+1, n-i-1, s);
        if (result == -1) return -1;
        else return result + i + 1; 
    } 

    if (s < arr[i]) {
        return binary_search_recursive(arr, i, s);
    }
}


int binary_search_wrong(int *arr, int n, int s) {
    if (n == 0) return -1;
    int i = n/2;

    if (s == arr[i]) {
        return i;
    } else if (s > arr[i]) {
        return binary_search_wrong(arr+i+1, n-i-1, s);
    } else {
        return binary_search_wrong(arr, i, s);
    }
}


int binary_search_iterative(int *arr, int n, int s) {
    int low = 0;
    int high = n - 1;
    int mid;
    while (high - low >= 0) { // high - low == 0 has to be considered as a normal case.
        mid = (high + low)/2;
        if (s == arr[mid]){
            return mid;
        } else if (s > arr[mid]) {
            low = mid + 1;
        } else if (s < arr[mid]){
            high = mid - 1;
        }
    }

    return -1;
}


int main() {
    int arr[] = {1,2,3,4,5,9,43,54};
    //int n = sizeof(arr) / sizeof(int);
    int n = 8;
    //printf("%d\n", arr);
    printf("%d\n", binary_search_iterative(arr, n, 3));
}














