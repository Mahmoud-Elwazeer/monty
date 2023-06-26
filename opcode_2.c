#include "monty.h"

/**
 * nop - do nothing
 * @top: pointer to pointer to top
 * @line_number: number of line
 * Return: void
 */

void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * swap - swaps top two elements in stack
 * @top: pointer to pointer to top
 * @line_number: number of line
 * Return: void
 */

void swap(stack_t **top, unsigned int line_number)
{
	int temp = 0;

	if ((*top)->next == NULL || *top == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}

/**
 * add - add top two element in stack and store the value in
 * second node
 * @top: pointer to pointer to top
 * @line_number: number of line
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	int temp = 0;

	if ((*top)->next == NULL || *top == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n + (*top)->next->n;
	(*top)->next->n = temp;
	pop(top, line_number);
}
