#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a given node
void insertAfter(Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }
    
    Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// Delete a specific node
void deleteNode(Node** head, Node* delNode) {
    if (*head == NULL || delNode == NULL) {
        printf("Invalid operation\n");
        return;
    }
    
    // If node to be deleted is head
    if (*head == delNode) {
        *head = delNode->next;
    }
    
    // Update next pointer of previous node
    if (delNode->prev != NULL) {
        delNode->prev->next = delNode->next;
    }
    
    // Update prev pointer of next node
    if (delNode->next != NULL) {
        delNode->next->prev = delNode->prev;
    }
    
    free(delNode);
}

void displayForward(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    
    Node* temp = head;
    printf("Forward: NULL <- ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

int main() {
    Node* head = NULL;
    
    printf("=== DOUBLY LINKED LIST ===\n\n");
    
    // Create initial list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Initial list:\n");
    displayForward(head);
    
    // Insert 25 after the second node (20)
    printf("\nInserting 25 after node with value 20:\n");
    insertAfter(head->next, 25);
    displayForward(head);
    
    // Insert 35 after the node with value 30
    printf("\nInserting 35 after node with value 30:\n");
    Node* temp = head;
    while (temp != NULL && temp->data != 30) {
        temp = temp->next;
    }
    insertAfter(temp, 35);
    displayForward(head);
    
    // Delete node with value 25
    printf("\nDeleting node with value 25:\n");
    temp = head;
    while (temp != NULL && temp->data != 25) {
        temp = temp->next;
    }
    deleteNode(&head, temp);
    displayForward(head);
    
    // Delete head node
    printf("\nDeleting head node (10):\n");
    deleteNode(&head, head);
    displayForward(head);
    
    return 0;
}