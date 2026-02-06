Question 1 documentation:

Stack Structure:
- Has an array called 'items' to store characters (max size 100)
- Has 'top' variable that points to the last element
- When empty, top = -1

Basic Stack Functions:
- initStack() - Makes a new empty stack
- push() - Adds element to stack
- pop() - Removes element from stack
- isEmpty() - Checks if stack is empty

Helper Functions:
- isOpeningBracket() - Returns true if character is '(', '[', or '{'
- isClosingBracket() - Returns true if character is ')', ']', or '}'
- isMatchingPair() - Checks if opening and closing brackets match

Main Function:
- isBalanced() - Checks if expression has balanced parentheses
  Goes through each character
  Pushes opening brackets to stack
  Pops and matches closing brackets
  Returns true if stack is empty at end


MAIN METHOD ORGANIZATION

1. Print program header
2. Define three test expressions:
   - "a + (b - c) * (d"
   - "m + [a - b * (c + d * {m)]"
   - "a + (b - c)"
3. Check each expression and print result
4. End program


SAMPLE OUTPUT

 BALANCED PARENTHESES CHECKER

Expression: a + (b - c) * (d
Result: NOT BALANCED

Expression: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression: a + (b - c)
Result: BALANCED

Explanation:
- First expression has unclosed '(' bracket
- Second expression has mismatched brackets ('{' closed with ')')
- Third expression has properly matched brackets