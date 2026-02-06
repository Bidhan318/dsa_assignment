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

typedef struct {
    int items[MAX];
    int top;
} IntStack;

void initIntStack(IntStack* s) {
    s->top = -1;
}

bool isIntStackEmpty(IntStack* s) {
    return s->top == -1;
}

void pushInt(IntStack* s, int item) {
    s->items[++(s->top)] = item;
}

int popInt(IntStack* s) {
    if (isIntStackEmpty(s)) {
        return 0;
    }
    return s->items[(s->top)--];
}

int evaluatePostfix(char* postfix) {
    IntStack stack;
    initIntStack(&stack);
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        char current = postfix[i];
        
        if (isdigit(current)) {
            pushInt(&stack, current - '0');
        }
        else if (isOperator(current)) {
            int val2 = popInt(&stack);
            int val1 = popInt(&stack);
            int result;
            
            switch(current) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }
            
            pushInt(&stack, result);
        }
    }
    
    return popInt(&stack);
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    
    printf(" INFIX TO POSTFIX CONVERTER AND EVALUATOR \n\n");
    
    strcpy(infix, "5+3*2");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    strcpy(infix, "(5+3)*2");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    strcpy(infix, "8+5*2-3");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n\n", evaluatePostfix(postfix));
    
    return 0;
}