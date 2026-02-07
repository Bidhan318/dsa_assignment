Question 6 documentation:

MIN HEAP AND MAX HEAP

Heap Structure:
- Array-based complete binary tree
- Has 'arr' to store elements
- Has 'size' to track number of elements

Array Indexing:
- Parent of node i: (i-1)/2
- Left child of node i: 2*i+1
- Right child of node i: 2*i+2

Min Heap Property:
- Parent is smaller than children
- arr[i] <= arr[2*i+1] and arr[i] <= arr[2*i+2]
- Smallest element at root (index 0)

Max Heap Property:
- Parent is larger than children
- arr[i] >= arr[2*i+1] and arr[i] >= arr[2*i+2]
- Largest element at root (index 0)

Basic Functions:
- initHeap() - Initializes heap with size 0
- swap() - Swaps two elements
- display() - Prints heap array

Heapify Functions:
- minHeapifyDown() - Maintains min heap property downward
  * Compares node with left and right children
  * Swaps with smallest child if needed
  * Recursively heapifies affected subtree

- maxHeapifyDown() - Maintains max heap property downward
  * Compares node with left and right children
  * Swaps with largest child if needed
  * Recursively heapifies affected subtree

Build Heap Functions:
- buildMinHeap() - Builds min heap from unsorted array
  * Copies array elements to heap
  * Heapifies from last non-leaf node to root
  * Starts at index (n/2)-1 and goes down to 0

- buildMaxHeap() - Builds max heap from unsorted array
  * Copies array elements to heap
  * Heapifies from last non-leaf node to root
  * Starts at index (n/2)-1 and goes down to 0


MAIN METHOD ORGANIZATION

1. Declare min heap and max heap
2. Create unsorted array: {45, 12, 78, 23, 56, 9, 34, 67, 19, 88}
3. Display original array
4. Build min heap from array
5. Display min heap
6. Build max heap from array
7. Display max heap


SAMPLE OUTPUT

Original array: 45 12 78 23 56 9 34 67 19 88 

Min Heap: 9 12 34 19 56 78 45 67 23 88 
Max Heap: 88 78 45 67 56 9 34 12 23 19 


HEAP VISUALIZATION

Min Heap Tree:
        9
      /   \
    12     34
   / \    / \
  19 56  78 45
 / \ 
67 23 88

Max Heap Tree:
        88
      /    \
    78      45
   / \     / \
  67 56   9  34
 / \
12 23 19


Explanation:
- buildMinHeap() creates heap where parent < children
- buildMaxHeap() creates heap where parent > children
- Both use heapifyDown() to maintain heap property
- Time complexity: O(n) for building heap
- Heapify starts from last non-leaf node ((n/2)-1)
