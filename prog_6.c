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

// Heapify up for insertion
void heapifyUp(Heap* h, int index) {
    int parent = (index - 1) / 2;
    
    if (index > 0 && h->arr[index] < h->arr[parent]) {
        swap(&h->arr[index], &h->arr[parent]);
        heapifyUp(h, parent);
    }
}

// Insert element into heap
void insert(Heap* h, int value) {
    if (h->size >= MAX) {
        printf("Heap is full!\n");
        return;
    }
    
    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

// Display heap
void display(Heap* h) {
    printf("Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main() {
    Heap h;
    initHeap(&h);
    
    insert(&h, 50);
    insert(&h, 30);
    insert(&h, 20);
    insert(&h, 15);
    insert(&h, 10);
    insert(&h, 8);
    insert(&h, 16);
    
    display(&h);
    
    return 0;
}
