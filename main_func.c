#include "monty.h"

/**
 * main - opens a monty fie in order to be parsed
 * @argc: argument counts
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS upon success, or EXIT_FAILURE if otherwise
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s monty file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE *file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 1;

	while (getline(&line, &len, file) != -1)
	{
		parse_line(line, &stack, line_number);
		line_number++;
	}

	free_stack(&stack);
	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
