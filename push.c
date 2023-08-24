#include "monty.h"

/**
 * _push - pushes a new node to the top of the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */
void _push(stack_t **head, (__attribute__((unused))unsigned int line))
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(head);
		exit(EXIT_FAILURE);
	}

	newNode->next = *head;
	newNode->prev = NULL;
	newNode->n = arg.arg;
	if (*head)
	{
		(*head)->prev = newNode;
	}	
	*head = newNode;
}





/**
 * _pall - prints all node data of the stack
 * @head: pointer to the head
 * @line: line counter
 * Return: void
 */
void _pall(stack_t **head, (__attribute__((unused))unsigned int line))
{
	stack_t *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%d/n", tmp->n);
		tmp = tmp->next;
	}
}
