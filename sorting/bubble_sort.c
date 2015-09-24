#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int n) {
    if (n == 0) return;

    int i, j, temp;
    // Sort the array from the smallest element to the largest element as the index increase from 0 to n.
    for (i = 0; i <= n; i++) {
        for (j = n-1; j >= i; j--) {
            if (arr[j] < arr[j-1]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

#define N 100
#define MAX 1000

int main() {
    int arr[N], i;
    for (i = 0; i < N; i++) {
        arr[i] = random() % MAX; 
        printf("%d\n", arr[i]);
    };

    printf("\n");

    bubble_sort(arr, N);
    for (i = 0; i< N; i++) printf("%d\n", arr[i]);
}