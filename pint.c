#include "monty.h"

/**
 * _pint - prints node to the top of the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */
void _pint(stack_t **head, unsigned int line)
{
	if !head || !(*head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	tmp = *head
	while (tmp)
	{
		if (tmp->prev == NULL)
			break;
		tmp = tmp->prev;
	}
	printf("%d\n", tmp->n);
}
