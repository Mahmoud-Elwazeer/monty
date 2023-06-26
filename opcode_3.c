#include "monty.h"

/**
 * _div - divides the second top element of the stack
 * by the top element of the stack.
 * @top: pointer to pointer to top
 * @line_number: number of line
 * Return: void
 */

void _div(stack_t **top, unsigned int line_number)
{
	int temp = 0;

	if ((*top)->next == NULL || *top == NULL || top == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->next->n / (*top)->n;
	(*top)->next->n = temp;
	pop(top, line_number);
}
