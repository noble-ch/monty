#include "monty.h"

/**
 * arthimetics - contains all arthimetic functions
 * add_operation - adds 2 top stack
 * @stack: pointer
 * @ln: line number of the opcode
 **/
void add_operation(stack_t **stack, unsigned int ln)
{
	if (*stack == NULL || !((*stack)->next))
	{
	fprintf(stderr, "L%d: can't add, stack too short\n", ln);
	free(glob.line);
	free_stack(*stack);
	exit(EXIT_FAILURE);
	}


	(*stack)->next->n += (*stack)->n;
	pop_operation(stack, ln);
}

/**
 * division_operation - divides the top element
 * @stack: double pointer
 * @ln: current ln file
 */
void division_operation(stack_t **stack, unsigned int ln)
{
	int result;
	stack_t *temp;

	switch ((*stack == NULL) || ((*stack)->next == NULL)) {
    case 0:
        /* Neither stack nor stack->next is NULL */
        temp = *stack;
        if (temp->n == 0) {
            fprintf(stderr, "L%d: division by zero\n", ln);
            exit(EXIT_FAILURE);
        }
        result = temp->next->n / temp->n;
        temp->next->n = result;
        *stack = temp->next;
        free(temp);
        break;
    case 1:
        /* Either stack or stack->next is NULL */
        fprintf(stderr, "L%d: can't div, stack too short\n", ln);
        exit(EXIT_FAILURE);
        break; /* This break is not necessary but included for clarity */
}
}

/**
 * mul_operation - multiplies top element
 * @stack: double pointer
 * @ln: current ln file
 */
void mul_operation(stack_t **stack, unsigned int ln)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	result = temp->next->n * temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}

/**
 * sub_operation - subtracts  top element
 * @stack: double pointer
 * @ln: current ln file
 */
void sub_operation(stack_t **stack, unsigned int ln)
{
	int result;
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*stack = temp->next;
	free(temp);
}
/*
 * modulo_operation - computes the modulus on the stack.
 * @stack: pointer
 * @ln: line number opcode
 */
void modulo_operation(stack_t **stack, unsigned int ln)
{
	int a, b;

	switch ((*stack == NULL) || ((*stack)->next == NULL)) {
    case 0:
        a = (*stack)->n;
        b = (*stack)->next->n;
        
        if (a == 0) {
            fprintf(stderr, "L%d: division by zero\n", ln);
            exit(EXIT_FAILURE);
        }
        break;
    case 1:
        fprintf(stderr, "L%d: can't mod, stack too short\n", ln);
        exit(EXIT_FAILURE);
        break; 
}

	(*stack)->next->n = b % a;
	pop_operation(stack, ln);
}
