#include "monty.h"

/**
 * parseline - tokenizes a line and stores in line struct
 * @line: struct containing line contents and number
 * @buffer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *buffer)
{
	unsigned int i;
	char *token = NULL;

	line->content = malloc(sizeof(char *) * 3);
	if (!line->content)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(buffer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->content[i] = token;
		token = strtok(NULL, " \n");
	}

	line->content[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
	size_t size = 0;
	mem_t *mem = NULL;
	line_t line;

	mem = malloc(sizeof(mem_t));
	if (!mem)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.content = NULL;

	mem->file = file;
	mem->stack = NULL;
	mem->buf = NULL;

	while (getline(&(mem->buf), &size, mem->file) != -1)
	{
		line.number++;
		parseline(&line, mem->buf);
		if (line.content)
			get_op_func(line, mem);
	}

	free(mem->buf);
	free_stack(&(mem->stack));
	fclose(mem->file);
	free(mem);
}
