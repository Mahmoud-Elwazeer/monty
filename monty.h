#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

extern int arg_push;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


char **split_string(char *str, char *delim);
int _strlen(char **av);

int read_file(FILE *file);
int execute(stack_t **top, char **av, unsigned int n);

void push(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void pop(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number);
void mul(stack_t **top, unsigned int line_number);
void _div(stack_t **top, unsigned int line_number);

void free_struct(stack_t *top);
void free_stack(stack_t **top);
void free_pointer(char **av);

int error_push(char *av);

#endif
