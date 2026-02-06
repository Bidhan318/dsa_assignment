#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, char item) {
    s->items[++(s->top)] = item;
}

char pop(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    Stack stack;
    initStack(&stack);
    int j = 0;
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        if (current == ' ')
            continue;
        
        if (isalnum(current)) {
            postfix[j++] = current;
        }
        else if (current == '(') {
            push(&stack, current);
        }
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (isOperator(current)) {
            while (!isEmpty(&stack) && peek(&stack) != '(' && 
                   precedence(peek(&stack)) >= precedence(current)) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, current);
        }
    }
    
    while (!isEmpty(&stack)) {
        postfix[j++] = pop(&stack);
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    
    printf("INFIX TO POSTFIX CONVERTER \n\n");
    
    strcpy(infix, "a+b*c");
    printf("Infix: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n\n", postfix);
    
    strcpy(infix, "(a+b)*c");
    printf("Infix: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n\n", postfix);
    
    strcpy(infix, "a+b*c-d");
    printf("Infix: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix: %s\n\n", postfix);
    
    return 0;
}