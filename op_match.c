#include "monty.h"

/**
 * get_op_func - matches opcode with appropriate function
 * @line: struct containing line contents and line number
 * @meta: struct containing meta information
 *
 * Return: Pointer to the function to be executed
 */
void (*get_op_func(line_t line, mem_t *meta))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pop", _pop},
		{"pint", _pint},
		{"swap", _swap},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (size_t i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(line.content[0], instructions[i].opcode) == 0)
		{
			if (is_push(instructions[i].opcode))
				return (_push);
			else
				return instructions[i].f;
		}
	}

	fprintf(stderr, "L%u: unknown instruction %s\n", line.number, line.content[0]);
	exit(EXIT_FAILURE);
}
