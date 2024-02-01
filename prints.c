#include "monty.h"

/**
 * print_operation - prints the value of the stack
 * @stack: pointer
 * @ln: line number
*/
void print_operation(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can not print, stack empty\n", ln);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}


/**
 * print_all_operation - prints all values
 * @stack: pointer
 * @ln: line number
 */
void print_all_operation(stack_t **stack, unsigned int ln)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		(void)ln;
	}

}

/**
 * print_char_operation - prints  character
 * @stack: pointer
 * @ln: current line number
 */
void print_char_operation(stack_t **stack, unsigned int ln)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can not print char, stack empty\n", ln);
		exit(EXIT_FAILURE);
	}

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", ln);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", value);
}

/**
 * print_str_operation - prints the string
 * @stack: double pointer
 * @ln: current line number
 */
void print_str_operation(stack_t **stack, unsigned int ln)
{
	stack_t *current = *stack;
	(void) ln;

	while (current && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
