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

int main() {
    char infix[MAX];
    char postfix[MAX];
    
    printf("INFIX TO POSTFIX CONVERTER \n\n");
    
    return 0;
}