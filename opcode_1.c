#include "monty.h"

/**
 * push - push data to stack
 * @top: pointer to pointer
 * @line_number: line number
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *newNode = NULL;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = arg_push;

	if (*top == NULL)
		*top = newNode;
	else
	{
		newNode->next = *top;
		(*top)->prev = newNode;
		*top = newNode;
	}

}

/**
 * pall - print stack
 * @top: head of stack
 * @line_number: line number
 * Retrun: void
 */
void pall(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pint - prints the top value of the stack
 * @top: pointer to a pointer to top node
 * @line_number: number of line
 * Return: void
 */

void pint(stack_t **top, unsigned int line_number)
{
	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}


/**
 * pop - removes the top element of the stack.
 * @top: pointer to a pointer to top node
 * @line_number: number of line
 * Return: void
 */

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;


	if (top == NULL || *top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (temp->next != NULL)
		temp->next->prev = temp->prev;
	*top = temp->next;
	free(temp);
}
