#include "monty.h"

/**
 * _add - adds the top two elements of the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */

void _add(stack_t **head, __attribute__((unused)) unsigned int line)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line);
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	stack_t *first_top = *head;
	stack_t *second_top = first_top->next;

	second_top->n += first_top->n;
	pop_stack(head);
}



#include "monty.h"

/**
 * _nop - does nothing
 * @head: pointer to the head of the stack
 * @line: line counter
 * Return: void
 */

void _nop(stack_t **head, __attribute__((unused)) unsigned int line)
{
	(void)head;
	(void)line;
}
