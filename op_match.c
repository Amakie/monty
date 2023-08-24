#include "monty.h"

/**
 * op_match - matches the correct function for the corresponding opcode
 * @mem: struct for memory 
 * @lines: struct for line contents
 * Return: function pointer
 */
void (*op_match(line_t lines, mem_t *mem)(stack_t **, unsigned int))
{
	unsigned int i;
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	for (int i = 0; ops[i].opcode; i++)
	{
		if (strcmp(ops[i].opcode, lines.content[0]) == 0)
		{
			push_check(lines, mem, ops[i].opcode);
			if (arg.flag == 1 &&
			strcmp(ops[i].opcode, "push") == 0)
			{
				if (lines.content)
					free(lines.content);
				return (qpush);
			}
			free(lines.content);
			return (ops[i].f);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line.number,
	lines.content[0]);
	free(lines.content);
	free(mem->buf);
	free_stack(&(mem->stack));
	fclose(mem->file);
	free(mem);
	exit(EXIT_FAILURE);
}
