#include "monty.h"
#include <stdio.h>

/**
 * _pint - prints node to the top of the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */
void _pint(stack_t **head, unsigned int line)
{
	if (!head || !(*head))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	    
	stack_t *tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	printf("%d\n", tmp->n);
}

/**
 * _swap - swaps the top two nodes
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */
void _swap(stack_t **head, unsigned int line)
{
	if (!head || !(*head) || !((*head)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	int tmp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = tmp;
}
