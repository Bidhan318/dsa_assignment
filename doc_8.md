Question 8 Documentation: SORTING ALGORITHMS COMPARISON

Program that generates random numbers and sorts them using different algorithms.
User chooses algorithm and sees performance statistics (comparisons and swaps).

PROGRAM FLOW
1. User enters N (how many random numbers to generate)
2. Program generates N random integers between 1 and 1000
3. Display numbers before sorting
4. User selects sorting algorithm (1-4)
5. Program sorts and counts operations
6. Display sorted numbers and statistics


SORTING ALGORITHMS

1. BUBBLE SORT
   - Compares adjacent elements and swaps if out of order
   - Repeats until no more swaps needed
   - Largest elements "bubble up" to the end
   
   Performance:
   - Comparisons: Always n(n-1)/2
   - Swaps: 0 to n(n-1)/2 (depends on initial order)
   - Time Complexity: O(n²)
   - Simple but slow for large datasets

2. SELECTION SORT
   - Finds minimum element and places it at beginning
   - Repeats for remaining unsorted portion
   
   Performance:
   - Comparisons: Always n(n-1)/2
   - Swaps: At most n-1 (only 1 swap per pass)
   - Time Complexity: O(n²)
   - Fewer swaps than bubble sort

3. INSERTION SORT
   - Builds sorted array one element at a time
   - Takes each element and inserts it in correct position
   - Shifts larger elements to make room
   
   Performance:
   - Comparisons: Varies (fewer if partially sorted)
   - Swaps: Same as comparisons
   - Time Complexity: O(n²) average, O(n) best case
   - Efficient for small or nearly sorted data

4. MERGE SORT
   - Divide and conquer approach
   - Splits array in half recursively
   - Merges sorted halves back together
   
   Performance:
   - Comparisons: ~n log n
   - Time Complexity: O(n log n)
   - Space Complexity: O(n) - needs extra memory
   - Much faster for large datasets
   - Stable sort (maintains order of equal elements)


HELPER FUNCTIONS

generateRandomNumbers():
- Fills array with random integers from 1 to 1000
- Uses rand() % 1000 + 1

printArray():
- Displays array contents
- Prints 10 numbers per line for readability

Each sorting function:
- Takes array, size, and pointers for comparison/swap counters
- Modifies array in-place (except merge sort uses temp arrays)
- Updates counter variables during execution


COUNTING OPERATIONS

Comparisons:
- Every time two elements are compared
- Incremented in if conditions

Swaps:
- Bubble Sort: actual element swaps
- Selection Sort: only when minimum is moved
- Insertion Sort: each shift counts as swap
- Merge Sort: counts when element taken from right subarray


SAMPLE EXECUTION

Input: N = 15
Random numbers generated: [342, 867, 123, 456, ...]

User chooses: Merge Sort
Result: [123, 123, 234, 234, 342, ...]

Statistics:
- Comparisons: 43
- Swaps: 8

Why Merge Sort is efficient:
- Uses divide and conquer strategy
- Reduces comparisons significantly for larger N
- O(n log n) vs O(n²) for other algorithms


ALGORITHM COMPARISON FOR N=15

Bubble Sort:     ~105 comparisons, ~50-60 swaps
Selection Sort:  ~105 comparisons, ~14 swaps  
Insertion Sort:  ~50-70 comparisons (varies), same swaps
Merge Sort:      ~43 comparisons, ~8 swaps

Note: For small N, difference isn't huge
      For N=1000, merge sort becomes dramatically faster
