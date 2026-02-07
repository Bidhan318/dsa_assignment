#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random integers
void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;  // Random number between 1 and 1000
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0)  // Print 10 numbers per line for better readability
            printf("\n");
    }
    if (n % 10 != 0)
        printf("\n");
}

// Bubble Sort with comparison and swap counting
void bubbleSort(int arr[], int n, long long *comparisons, long long *swaps) {
    *comparisons = 0;
    *swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comparisons)++;  // Count each comparison
            
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;  // Count each swap
            }
        }
    }
}

int main() {
    int n;
    long long comparisons, swaps;
    
    // Seed random number generator
    srand(time(NULL));
    
    // Get input from user
    printf("Enter the number of random integers to generate (N): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid input! N must be a positive integer.\n");
        return 1;
    }
    
    // Allocate memory for array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Generate random numbers
    generateRandomNumbers(arr, n);
    
    // Print numbers before sorting
    printf("\n--- Numbers Before Sorting ---\n");
    printArray(arr, n);
    
    // Perform Bubble Sort
    printf("\nSorting using Bubble Sort...\n");
    bubbleSort(arr, n, &comparisons, &swaps);
    
    // Print numbers after sorting
    printf("\n--- Numbers After Sorting ---\n");
    printArray(arr, n);
    
    // Display statistics
    printf("\n--- Sorting Statistics ---\n");
    printf("Algorithm: Bubble Sort\n");
    printf("Total Comparisons: %lld\n", comparisons);
    printf("Total Swaps: %lld\n", swaps);
    
    // Free allocated memory
    free(arr);
    
    return 0;
}
