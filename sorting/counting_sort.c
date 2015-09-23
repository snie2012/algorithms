#include <stdio.h>
#include <stdlib.h>

/*
int *counting_sort_stable(int *array, int n, int min, int max) {
    int i, j, z;
    int sorted[n];

    int range = max - min + 1;
    int *count = malloc(range * sizeof(*array));

    for (i = 0; i < range; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[array[i] - min]++;

    for (i = 1; i < range; i++) count[i] = count[i] + count[i-1];

    for (i = n-1; i >= 0; i--) {
        sorted[count[array[i]]] = array[i];
        count[array[i]]--;
    }

    free(count);

    return sorted;
}
*/

void counting_sort_stable(int *array, int n, int min, int max) {
    int i, j, z;

    int range = max - min + 1;
    int *count = malloc(range * sizeof(*array));
    int *sorted = malloc(n * sizeof(*array));

    for (i = 0; i < range; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[array[i] - min]++;

    for (i = 1; i < range; i++) count[i] = count[i] + count[i-1];

    for (i = n-1; i >= 0; i--) {
        sorted[count[array[i]]] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < n; i++) array[i] = sorted[i];


    free(count);
    free(sorted);
}


void counting_sort_instable(int *array, int n, int min, int max) {
    int i, j, z;

    int range = max - min + 1;
    int *count = malloc(range * sizeof(*array));


    for (i = 0; i < range; i++) count[i] = 0;
    for (i = 0; i < n; i++) count[array[i] - min]++;

    z = 0;
    for (i = 0; i < range; i++) {
        if (count[i] != 0) {
            for (j = 0; j < count[i]; j++) {
                array[z++] = i;
            }
        }
    }

    free(count);
}


void find_min_max(int *array, int n) {
    int i, min, max;

    for (i = 0; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        } else if (array[i] > max) {
            max = array[i];
        }
    }
}


#define N 10
#define MAX 1000

int main() {
    int arr[N], i;

    for (i = 0; i < N; i++) arr[i] = rand() %  MAX;

    counting_sort_stable(arr, N, 0, MAX);

    for (i = 0; i < N; i++) printf("%d\n", arr[i]);
    return EXIT_SUCCESS;
}









