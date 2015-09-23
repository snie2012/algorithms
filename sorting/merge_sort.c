#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int n, int m){
    int i, j, k;
    int *temp = malloc(n * (sizeof(int))); // or malloc(n*(sizeof(*a)))

    i = 0;
    k = 0;
    j = m;

    // The condition of while loop is crucial, because the first half can be totally larger or smaller than 
    // the the second half before iterating through the other half. 
    // At this point, the comparison between these two half should stop. Next, put all the remaining 
    // elements in the larger half into the sorted array.
    while (k <= m-1 && j <= n-1) {
        if (a[k] < a[j]) {
            temp[i++] = a[k++];
        } else {
            temp[i++] = a[j++];
        }
    };

    while (k <= m-1) {
        temp[i++] = a[k++]; 
    };

    while (j <= n-1) {
        temp[i++] = a[j++];
    }

    for (i = 0; i < n; i++) {
        a[i] = temp[i];
    };

    free(temp);
}


void merge_sort(int *a, int n){
    if (n < 2) {
        return;
    } else {
        int m = n/2;
        merge_sort(a, m);
        merge_sort(a+m, n-m);
        merge(a, n, m);
    }
}



#define N 15
#define MAX 1000

int main() {
    int arr[N], i;
    for (i = 0; i < N; i++) arr[i] = rand() %  MAX;
    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    printf("\n");
    merge_sort(arr, N);
    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    return EXIT_SUCCESS;
}

