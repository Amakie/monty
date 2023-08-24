#include "monty.h"

/**
 * _pop - pops the top element off the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */

void _pop(stack_t **head, __attribute__((unused)) unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	stack_t *temp = *head;

	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	free(temp);
}
