# Monty Project

Authors: Victor Egele (vegele93@gmail.com) and Constance Amatey (consamate57@gmail.com)

## General

In computer science, **LIFO** (Last-In-First-Out) and **FIFO** (First-In-First-Out) are two common data structures used to manage collections of elements. They are fundamental concepts in data processing and memory management.

A **stack** is a linear data structure that follows the LIFO principle, meaning that the last element added is the first to be removed. Stacks are used to manage function calls, expression evaluation, and memory management. A **queue** is a linear data structure that follows the FIFO principle, where the first element added is the first to be removed. Queues are used in scenarios such as scheduling, breadth-first search, and printing tasks.

The project involves implementing a stack and queue data structure using the Monty scripting language. This language uses opcodes to perform operations on the stack. The most common implementations of stacks and queues are using arrays or linked lists.

## Common Use Cases

- Stacks: Used for implementing function calls and recursion tracking, expression evaluation (postfix notation), backtracking in algorithms, and managing memory in a limited environment.
- Queues: Used in scheduling tasks, breadth-first search algorithms, handling requests in real-time systems, and managing tasks in print spooling.

## Compilation

To compile the Monty project, use the following command:

```$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```

## Tasks

### 0. Push, Pull
Implement the ```push``` and ```pall``` opcodes.

**The push opcode**

The opcode ```push``` pushes an element to the stack.

- Usage: ```push <int>```
	- where ```<int>``` is an integer
- if ```<int>``` is not an integer or if there is no argument given to push, print the error message ```L<line_number>: usage: push integer```, followed by a new line, and exit with the status ```EXIT_FAILURE```
	- where is the line number in the file
- You won’t have to deal with overflows. Use the ```atoi``` function

**The pall opcode**

The opcode ```pall``` prints all the values on the stack, starting from the top of the stack.

- Usage ```pall```
- Format: see example
- If the stack is empty, don’t print anything

### 1. Pint
Implement the ```pint``` opcode.

**The pint opcode**

The opcode pint prints the value at the top of the stack, followed by a new line.

- Usage: ```pint```
- If the stack is empty, print the error message ```L<line_number>: can't pint, stack empty```, followed by a new line, and exit with the status ```EXIT_FAILURE```

### 2. Pop
Implement the ```pop``` opcode.

**The pop opcode**

The opcode ```pop``` removes the top element of the stack.

- Usage: ```pop```
- If the stack is empty, print the error message ```L<line_number>: can't pop an empty stack```, followed by a new line, and exit with the status ```EXIT_FAILURE```

### 3. swap
Implement the ```swap``` opcode.

**The swap opcode**

The opcode swap swaps the top two elements of the stack.

- Usage: ```swap```
- If the stack contains less than two elements, print the error message ```L<line_number>: can't swap, stack too short```, followed by a new line, and exit with the status ```EXIT_FAILURE```

### 4. add
Implement the ```add``` opcode.

**The add opcode**

The opcode ```add``` adds the top two elements of the stack.

- Usage: ```add```
 If the stack contains less than two elements, print the error message ```L<line_number>: can't add, stack too short```, followed by a new line, and exit with the status ```EXIT_FAILURE```
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
	- The top element of the stack contains the result
	- The stack is one element shorter

### 5. nop
Implement the ```nop``` opcode.

**The nop opcode**

The opcode ```nop``` doesn’t do anything.

- Usage: ```nop```
