Question 2 documentation:

DOUBLY LINKED LIST STRUCTURE

Node Structure:
- Has 'data' to store integer value
- Has 'prev' pointer pointing to previous node
- Has 'next' pointer pointing to next node

Basic Functions:
- createNode() - Creates a new node with given data
- insertAtEnd() - Adds node at the end of list
- displayForward() - Prints list from head to tail

Required Functions:
- insertAfter() - Inserts new node after a given node
  * Takes previous node and data as parameters
  * Creates new node
  * Links new node between previous node and its next node
  * Updates all four pointers (prev and next of both nodes)

- deleteNode() - Deletes a specific node from list
  * Takes head pointer and node to delete
  * Updates head if deleting first node
  * Links previous node to next node
  * Links next node to previous node
  * Frees memory of deleted node


MAIN METHOD ORGANIZATION

1. Print program header
2. Create initial list with values: 10, 20, 30, 40, 50
3. Display initial list
4. Insert 25 after node with value 20
5. Display updated list
6. Insert 35 after node with value 30
7. Display updated list
8. Delete node with value 25
9. Display updated list
10. Delete head node (10)
11. Display final list


SAMPLE OUTPUT

=== DOUBLY LINKED LIST ===

Initial list:
Forward: NULL <- 10 <-> 20 <-> 30 <-> 40 <-> 50 -> NULL

Inserting 25 after node with value 20:
Forward: NULL <- 10 <-> 20 <-> 25 <-> 30 <-> 40 <-> 50 -> NULL

Inserting 35 after node with value 30:
Forward: NULL <- 10 <-> 20 <-> 25 <-> 30 <-> 35 <-> 40 <-> 50 -> NULL

Deleting node with value 25:
Forward: NULL <- 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 -> NULL

Deleting head node (10):
Forward: NULL <- 20 <-> 30 <-> 35 <-> 40 <-> 50 -> NULL

Explanation:
- List starts with 5 nodes
- insertAfter() adds nodes in middle of list
- deleteNode() removes nodes and maintains links
- Both operations preserve bidirectional links