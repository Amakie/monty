#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define TRUE 1

typedef struct stack_s stack_t;
typedef struct instruction_s instruction_t;
typedef struct line_s line_t;
typedef struct mem_s mem_t;
typedef struct arg_s arg_t;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
};

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
};

/**
 * struct line - contents of line and corresponding number
 * @contents: array of tokens read from the line
 * @number: the line number
 *  
 *  Description: contents of a line and corresponding number
 */
struct line_s
{
	unsigned int number;
	char **content;
};

/**
 * struct stack_s - struct for memory allocation
 * @buf: buffer
 * @stack: stack node
 * @file: file
 */
struct mem_s
{
	char *buf;
	stack_t *stack;
	FILE *file;
};

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack
 * @next: points to the next element of the stack
 *  
 *  Description: Doubly linked list struct for stacks and queus project
 */
struct arg_s
{
	int arg;
	int flag;
};

extern arg_t arg;

void _push(stack_t **head, unsigned int line_number);
void _pall(stack_t **head, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);
int main(int argc, char *argv[]);
void free_stack(stack_t **head);

int is_push(char *opcode);
void parsefile(FILE *file);
void (*get_op_func(line_t line, mem_t *mem))(stack_t **stack, unsigned int line_number);
void parseline(line_t *line, char *buffer);

bool comment_check(line_t line);
bool argument_check(char *token);
void push_check(line_t line, mem_t *mem, char *opcode);

#endif
