#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * struct global_s - variables to args
 * @arg: value
 * @line: input 
 * @file: monty file pointer
 *
 * Description: variables that carries values through the program
 */
typedef struct global_s
{
	char *arg;
	FILE *file;
	char *line;
} glob_t;

extern glob_t glob;

/**
 * struct stack_s - doubly linked 
 * @n: integer
 * @prev: points to the previous element queue
 * @next: points to the next element oqueue
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: handle the opcode
 *
 * Description: opcode and its function
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int ln);
} instruction_t;

void execute_file(stack_t **stack);
void execute_opcode(char *opcode, stack_t **stack, unsigned int ln);

void push_operation(stack_t **stack, unsigned int ln);
void print_all_operation(stack_t **stack, unsigned int ln);
void print_operation(stack_t **stack, unsigned int ln);
void pop_operation(stack_t **stack, unsigned int ln);
void swap_operation(stack_t **stack, unsigned int ln);
void add_operation(stack_t **stack, unsigned int ln);
void null_operation(stack_t **stack, unsigned int ln);
void sub_operation(stack_t **stack, unsigned int ln);
void division_operation(stack_t **stack, unsigned int ln);
void mul_operation(stack_t **stack, unsigned int ln);
void modulo_operation(stack_t **stack, unsigned int ln);
void print_char_operation(stack_t **stack, unsigned int ln);
void print_str_operation(stack_t **stack, unsigned int ln);

stack_t *add_node(stack_t **stack, const int n);
int is_number(char *str);
void free_stack(stack_t *stack);

#endif /* monty.h */
