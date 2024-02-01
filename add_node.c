#include "monty.h"

/**
 * add_node - adds a new node to the list
 * @stack: pointer to pointer of the top of the stack
 * @n: value to be added to the new node
 *
 * Return: pointer to the newly added node
 */
stack_t *add_node(stack_t **stack, const int n)
{
	stack_t *new_node;

new_node = malloc(sizeof(stack_t));
	switch (new_node == NULL)
	{
	case 0:
		break;
	case 1:
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		exit(EXIT_FAILURE);
		break;
}

new_node->n = n;
new_node->prev = NULL;
new_node->next = (*stack == NULL) ? NULL : *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;

*stack = new_node;
return (new_node);
}
