#include "monty.h"
/**
 * push - push data to stack
 * @top: pointer to pointer
 * @data: data of the stack
 * Return: void
 */

void push(stack_t **top, unsigned int data)
{
	stack_t *newNode = NULL;

	newNode = malloc(sizeof(stack_t *));
	if (newNode == NULL)
	{
		fprintf(stder, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->n = data;

	if (*top == NULL)
		*top = newNode;
	else
	{
		newNode->next = *top;
		(*top)->prev = newNode;
		*top = newNode;
	}
	
}
