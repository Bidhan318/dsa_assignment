#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} Heap;

void initHeap(Heap* h) {
    h->size = 0;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyDown(Heap* h, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < h->size && h->arr[left] < h->arr[smallest])
        smallest = left;
    
    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;
    
    if (smallest != index) {
        swap(&h->arr[index], &h->arr[smallest]);
        minHeapifyDown(h, smallest);
    }
}

void maxHeapifyDown(Heap* h, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if (left < h->size && h->arr[left] > h->arr[largest])
        largest = left;
    
    if (right < h->size && h->arr[right] > h->arr[largest])
        largest = right;
    
    if (largest != index) {
        swap(&h->arr[index], &h->arr[largest]);
        maxHeapifyDown(h, largest);
    }
}

void buildMinHeap(Heap* h, int arr[], int n) {
    h->size = n;
    
    for (int i = 0; i < n; i++) {
        h->arr[i] = arr[i];
    }
    
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapifyDown(h, i);
    }
}

void buildMaxHeap(Heap* h, int arr[], int n) {
    h->size = n;
    
    for (int i = 0; i < n; i++) {
        h->arr[i] = arr[i];
    }
    
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapifyDown(h, i);
    }
}

void display(Heap* h) {
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    Heap minHeap, maxHeap;
    
    int arr[] = {45, 12, 78, 23, 56, 9, 34, 67, 19, 88};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    initHeap(&minHeap);
    buildMinHeap(&minHeap, arr, n);
    printf("Min Heap: ");
    display(&minHeap);
    
    initHeap(&maxHeap);
    buildMaxHeap(&maxHeap, arr, n);
    printf("Max Heap: ");
    display(&maxHeap);
    
    return 0;
}