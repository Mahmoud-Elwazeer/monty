#include "monty.h"

/**
 * push - push data to stack
 * @top: pointer to pointer
 * @data: data of the stack
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *newNode = NULL;
	(void)line_number;

	newNode = malloc(sizeof(stack_t *));
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


void pall(stack_t **top, unsigned int line_number)
{
	stack_t *temp = *top;
	(void)line_number;

	if (temp == NULL)
		return;
	while(temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}

}
