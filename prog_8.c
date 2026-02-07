#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    if (n % 10 != 0)
        printf("\n");
}

void bubbleSort(int arr[], int n, long long *comparisons, long long *swaps) {
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, long long *comparisons, long long *swaps) {
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Swap if needed
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*swaps)++;
        }
    }
}

int main() {
    int n, choice;
    long long comparisons, swaps;
    
    srand(time(NULL));
    
    printf("Enter the number of random integers to generate (N): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! N must be a positive integer.\n");
        return 1;
    }
    
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    generateRandomNumbers(arr, n);
    
    printf("\n--- Numbers Before Sorting ---\n");
    printArray(arr, n);
    
    // Display sorting options
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);
    
    // Perform sorting based on choice
    switch(choice) {
        case 1:
            printf("\nSorting using Bubble Sort...\n");
            bubbleSort(arr, n, &comparisons, &swaps);
            break;
        case 2:
            printf("\nSorting using Selection Sort...\n");
            selectionSort(arr, n, &comparisons, &swaps);
            break;
        default:
            printf("Invalid choice!\n");
            free(arr);
            return 1;
    }
    
    printf("\n--- Numbers After Sorting ---\n");
    printArray(arr, n);
    
    printf("\n--- Sorting Statistics ---\n");
    if (choice == 1)
        printf("Algorithm: Bubble Sort\n");
    else if (choice == 2)
        printf("Algorithm: Selection Sort\n");
    printf("Total Comparisons: %lld\n", comparisons);
    printf("Total Swaps: %lld\n", swaps);
    
    free(arr);
    
    return 0;
}