#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // choose last element as pivot
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // swap arr[i+1] and arr[high] (pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}

// uick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int sizes[] = {200000, 500000, 1500000, 500000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(NULL));

    for (int s = 0; s < numSizes; s++) {
        int N = sizes[s];
        int *arr = (int *)malloc(N * sizeof(int));

        // Generate random integers
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 1000000;
        }

        clock_t start = clock();
        quickSort(arr, 0, N - 1);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("N = %d, Time taken = %f seconds\n", N, time_taken);

        free(arr);
    }

    return 0;
}
