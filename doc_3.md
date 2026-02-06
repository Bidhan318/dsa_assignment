Question 3 documentation:

(a) DATA STRUCTURES

Node Structure:
- Has 'data' to store integer value
- Has 'next' pointer to the next node
- NULL means end of list

(b) FUNCTIONS IMPLEMENTED

Basic Functions:
- createNode() - Creates a new node with given data
- insertAtEnd() - Adds node at the end of list
- display() - Prints list from start to end

Reverse Traversal Functions:
- reverseTraversal() - Recursively traverses list in reverse
  Goes to end of list first
  Prints data while returning back
  Uses recursion to achieve reverse order
  
- displayReverse() - Wrapper function to print reverse list

(c) MAIN METHOD ORGANIZATION

1. Create empty list (head = NULL)
2. Insert 5 nodes: 10, 20, 30, 40, 50
3. Display normal list
4. Display reverse list
5. End program


(d) SAMPLE OUTPUT

 LINKED LIST REVERSE TRAVERSAL 


List: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Reverse List: 50 -> 40 -> 30 -> 20 -> 10 -> NULL

Explanation:
- Normal traversal goes: 10 → 20 → 30 → 40 → 50
- Reverse traversal goes: 50 → 40 → 30 → 20 → 10
- Uses recursion to print in reverse without changing the list structure