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
 * swap - swaps two elements
 * @top: pointer to pointer to top
 * @line_number: number of line
 * Return: void
 */

void swap(stack_t **top, unsigned int line_number)
{
	int temp;

	if ((*top)->next == NULL || *top == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit (EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->n = (*top)->next->n;
	(*top)->next->n = temp;
}
