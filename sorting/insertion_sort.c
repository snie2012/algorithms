#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *arr, int n) {
    int *temp_arr = malloc(n * sizeof(int));
    int i, j;

    temp_arr[0] = arr[0];
    for (i = 1; i < n; i++) {
        temp_arr[i] = arr[i];
        for (j = i-1; j >= 0; j--) {
            if (arr[i] < temp_arr[j]) {
                // use arr[i] to avoid using an additional variable to swap
                // because arr[i] doesn't change in the inner loop
                temp_arr[j+1] = temp_arr[j]; 
                temp_arr[j] = arr[i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp_arr[i];
    }

    free(temp_arr);
}

void insertion_sort_inplace(int *arr, int n) {
    int i, j, temp;
    for (i = 0; i < n; i++) {
        temp = arr[i];
        for (j = i-1; j >= 0; j--) {
            if (temp < arr[j]) {
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}


#define N 5
#define MAX 100

int main() {    
    int arr[N], i;
    for (i = 0; i < N; i++) {
        arr[i] = rand() %  MAX;
        printf("%d\n", arr[i]);
    };

    printf("\n");
    
    insertion_sort_inplace(arr, N);
    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    return EXIT_SUCCESS;
}



















