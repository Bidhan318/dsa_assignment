#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%c ", s->items[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    
    printf("Pushing: ( [ {\n");
    push(&stack, '(');
    push(&stack, '[');
    push(&stack, '{');
    display(&stack);
    
    printf("\nPopped: %c\n", pop(&stack));
    display(&stack);
    
    printf("\nPushing: ) ]\n");
    push(&stack, ')');
    push(&stack, ']');
    display(&stack);
    
    printf("\nPopping all:\n");
    while (!isEmpty(&stack)) {
        printf("%c ", pop(&stack));
    }
    printf("\n");
    display(&stack);
    
    return 0;
}