#include "monty.h"

/**
 * _pop - pops the top element off the stack
 * @head: pointer to the head
 * @line: line number
 * Return: void
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *temp = *head;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line);
		exit(EXIT_FAILURE);
	}

	*head = (*head)->next;

	if (*head)
		(*head)->prev = NULL;

	free(temp);
}
