#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

// Check if character is opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Check if character is closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Check if brackets form a matching pair
bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

// Main function to check if expression has balanced parentheses
bool isBalanced(char* expression) {
    Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        char current = expression[i];
        
        // Push opening brackets to stack
        if (isOpeningBracket(current)) {
            push(&stack, current);
        }
        // For closing brackets, check matching
        else if (isClosingBracket(current)) {
            // No matching opening bracket
            if (isEmpty(&stack)) {
                return false;
            }
            
            char top = pop(&stack);
            // Check if popped bracket matches current closing bracket
            if (!isMatchingPair(top, current)) {
                return false;
            }
        }
    }
    
    // Stack should be empty if balanced
    return isEmpty(&stack);
}

void checkExpression(char* expression) {
    printf("\nExpression: %s\n", expression);
    
    if (isBalanced(expression)) {
        printf("Result: BALANCED\n");
    } else {
        printf("Result: NOT BALANCED\n");
    }
}

int main() {
    printf(" BALANCED PARENTHESES CHECKER \n");
    
    // Test the three expressions from question
    char expr1[] = "a + (b - c) * (d";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    
    checkExpression(expr1);
    checkExpression(expr2);
    checkExpression(expr3);
    
    return 0;
}