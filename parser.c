#include "monty.h"

/**
 * parse_line - tokenizes a line of text, storing it in line struct
 * @line: struct containing line contents and line number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parse_line(line_t *lines, char *buffer)
{
	unsigned int i = 0;
	char *token = NULL;

	lines->content = malloc(sizeof(char *) * 3);
	if (lines->content == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	while (token && i < 2)
	{
		lines->content[i] = token;
		token = strtok(NULL, " \n");
	}
	i++;

	lines->content[i] = NULL;
}
