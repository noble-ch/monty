#include "monty.h"

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
stack_t *current;

for (; stack != NULL; stack = stack->next)
{
current = stack;
free(current);
}
}
