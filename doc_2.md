Question 2 documentation:

(a) DATA STRUCTURES


Stack Structure (for conversion):
- Has array 'items' to store characters (max size 100)
- Has 'top' variable pointing to last element
- When empty, top = -1

IntStack Structure (for evaluation):
- Has array 'items' to store integers (max size 100)
- Has 'top' variable pointing to last element
- When empty, top = -1


(b) FUNCTIONS IMPLEMENTED

Stack Functions (for conversion):
- initStack() - Initialize empty stack
- push() - Add character to stack
- pop() - Remove and return character from stack
- peek() - View top element without removing
- isEmpty() - Check if stack is empty

IntStack Functions (for evaluation):
- initIntStack() - Initialize empty integer stack
- pushInt() - Add integer to stack
- popInt() - Remove and return integer from stack
- isIntStackEmpty() - Check if stack is empty

Helper Functions:
- isOperator() - Check if character is +, -, *, /
- precedence() - Return operator priority (1 for +/-, 2 for *//)

Main Functions:
- infixToPostfix() - Convert infix expression to postfix
  Scan each character
  If operand, add to output
  If operator, handle based on precedence
  If '(', push to stack
  If ')', pop until '(' found

- evaluatePostfix() - Calculate result from postfix expression
  Scan each character
  If digit, push to stack
  If operator, pop two values, calculate, push result
  Return final value


(c) MAIN METHOD ORGANIZATION

1. Declare infix and postfix string arrays
2. Print program header
3. Test three expressions:
   - "5+3*2"
   - "(5+3)*2"
   - "8+5*2-3"
4. For each expression:
   - Convert to postfix
   - Evaluate the postfix
   - Print all results
5. End program


(d) SAMPLE OUTPUT

 INFIX TO POSTFIX CONVERTER AND EVALUATOR 

Infix Expression: 5+3*2
Postfix Expression: 532*+
Evaluation Result: 11

Infix Expression: (5+3)*2
Postfix Expression: 53+2*
Evaluation Result: 16

Infix Expression: 8+5*2-3
Postfix Expression: 852*+3-
Evaluation Result: 15


Explanation:
- First: 5+3*2 → 532*+ → (3*2=6, 5+6=11)
- Second: (5+3)*2 → 53+2* → (5+3=8, 8*2=16)
- Third: 8+5*2-3 → 852*+3- → (5*2=10, 8+10=18, 18-3=15)