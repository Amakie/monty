# monty

## The monty program
## Authors: [Constance Amatey](consamate57@gmail.com) and [Victor Egele](vegele93@gmail.com)

### Mandatory  Tasks:

#### 0. Push, Pull
Implement the push and pall opcodes.
**The push opcode**

The opcode push pushes an element to the stack.

Usage: push <int>
where <int> is an integer
if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function

**The pall opcode**

The opcode pall prints all the values on the stack, starting from the top of the stack.

Usage pall
Format: see example
If the stack is empty, don’t print anything

#### 1. Pint
Implement the pint opcode.
**The pint opcode**

The opcode pint prints the value at the top of the stack, followed by a new line.

Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

