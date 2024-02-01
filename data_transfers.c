#include "monty.h"

/**
 * push_operation - Adds an element to the top of the stack
 * @stack: pointer
 * @ln: current ln in opcode file
 */
void push_operation(stack_t **stack, unsigned int ln)
{
	int n;

	if (glob.arg == NULL || !is_number(glob.arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}

	n = atoi(glob.arg);
	if (add_node(stack, n) == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(glob.file);
		free(glob.line);
		exit(EXIT_FAILURE);
	}
}

/**
 * is_number - checks if a string is a number
 * @str: string to check
 * Return: 1 if number, else 0
 */
int is_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	if (*str == '-' || *str == '+')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);

		str++;
	}

	return (1);
}

/**
 * pop_operation - removes the top element of the stack
 * @stack: pointer to the top of the stack
 * @ln: line number of the opcode
 **/
void pop_operation(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	free(*stack);
	*stack = temp;
	if (*stack != NULL)
		(*stack)->prev = NULL;
}

/**
 * swap_operation - swaps the two elements from the stack
 * @stack: pointer
 * @ln: ln of the opcode
*/
void swap_operation(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free(glob.line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)

	temp->next->prev = *stack;
	temp->prev = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
}
