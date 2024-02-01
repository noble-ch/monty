#include "monty.h"

/**
 * execute_file - reads and executes opcodes from a file
 * @stack: pointer to the top of the stack
 */
void execute_file(stack_t **stack)
{
	char *opcode = NULL;
	size_t len = 0;
	ssize_t nread;
	unsigned int ln = 0;

	while ((nread = getline(&glob.line, &len, glob.file)) != -1)
	{
		ln++;
		opcode = strtok(glob.line, " \t\r\n\a");
		glob.arg = strtok(NULL, " \n\t");
		if (opcode == NULL || *opcode == '#')
			continue;
		execute_opcode(opcode, stack, ln);
	}
}

/**
 * execute_opcode - executes a single opcode
 * @opcode: opcode to execute
 * @stack: pointer
 * @ln: the opcode line number
 */
void execute_opcode(char *opcode, stack_t **stack, unsigned int ln)
{
	instruction_t instructions[] = {
		{"push", push_operation},
		{"pall", print_all_operation},
		{"pint", print_operation},
		{"pop", pop_operation},
		{"swap", swap_operation},
		{"nop", null_operation},
		{"add", add_operation},
		{"sub", sub_operation},
		{"div", division_operation},
		{"mul", mul_operation},
		{"mod", modulo_operation},
		{"pchar", print_char_operation},
		{"pstr", print_str_operation},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, ln);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", ln, opcode);
	free_stack(*stack);
	fclose(glob.file);
	free(glob.line);
	exit(EXIT_FAILURE);
}
