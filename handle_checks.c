#include "monty.h"

arg_t arg = {0, 0};

/**
 * comment_check - checks if line is a comment
 * @line: struct containing line contents and line number
 *
 * Return: true if comment, or false if otherwise
 */
bool comment_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid argument, else false
 */
bool argument_check(char *token)
{
	if (!token)
		return (false);

	for (unsigned int i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - check if push opcode is being used and sets global
 * argument variable if true
 * @line: struct containing line contents and line number
 * @mem: struct containing all allocated memory
 * @opcode: the opcode to compare
 *
 * Return: Nothing.
 */
void push_check(line_t line, mem_t *mem, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(mem->buf);
		free_stack(&(mem->stack));
		fclose(mem->file);
		free(mem);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
	{
		arg.arg = atoi(line.content[1]);
	}
}
