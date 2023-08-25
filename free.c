#include "monty.h"

/**
 * free_stack - frees all nodes in a stack
 * @stack: pointer to the head node pointer of stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t **head)
{
	stack_t *tmp = NULL;

	if (!head || !(*head))
		return;

	while (*head != NULL)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
