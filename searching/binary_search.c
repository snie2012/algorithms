#include <stdio.h>
#include <stdlib.h>

int binary_search(int *arr, int n, int s) {
    if (n == 0) return -1;
    int i = n/2;
    if (s == arr[i]) {
        return i;
    } else if (s > arr[i]) {
        int result = binary_search(arr+i+1, n-i-1, s);
        
        if (result == -1) return -1;
        else return result + i + 1; 
    } 

    if (s < arr[i]) return binary_search(arr, i, s);
}

int main() {
    int arr[] = {1,2,3,4,5};
    //int n = sizeof(arr) / sizeof(int);
    int n = 5;
    printf("%d\n", binary_search(arr, n, 5));
}