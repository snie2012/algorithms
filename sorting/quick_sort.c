#include <stdio.h>
#include <stdlib.h>


/* Arrange the N elements of ARRAY in random order.
   Only effective if N is much smaller than RAND_MAX;
   if this may not be the case, use a better random
   number generator. */
#define RAND_MAX 1000
void shuffle(int *array, size_t n){
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

int partition(int *arr, int n, int pivot) {
    int i, j, temp;
    // Pay attention to this loop. It's the key step that makes in-place sorting work.
    for (i = 0, j = n - 1;; i++, j--) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i >= j) break;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    return i;
}


void quick_sort(int *arr, int n){
    if (n < 2) return;

    //int less[n], more[n];
    int *less = malloc(n * (sizeof(int)));
    int *more = malloc(n * (sizeof(int)));

    int i, j, k; 
    int pivot = arr[n-1];

    j = 0;
    k = 0;
    for (i = 0; i < n-1; i++) {
        if (arr[i] < pivot) {
            less[j] = arr[i];
            j++;
        } else {
            more[k] = arr[i];
            k++;
        }
    };

    arr[j] = pivot;
    for (i = 0; i < j; i++) {
        arr[i] = less[i];
    };
    for (i = 0; i < k; i++) {
        arr[i+j+1] = more[i];
    }
    
    quick_sort(arr, j);
    quick_sort(arr+j+1, k);

    free (less);
    free (more);
}

void quick_sort_inplace(int *arr, int n){
    if (n < 2) return;

    int pivot = arr[n/2];

    int p = partition(arr, n, pivot);

    quick_sort(arr, p);
    quick_sort(arr+p, n-p);
}

#define N 10
#define MAX 1000

int main() {
    int arr[N], i;
    for (i = 0; i < N; i++) {
        arr[i] = rand() %  MAX;
        printf("%d\n", arr[i]);
    };

    printf("\n");
    
    quick_sort_inplace(arr, N);
    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    return EXIT_SUCCESS;
}
















