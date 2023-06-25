#include "monty.h"

int arg_push;


/**
 * read_file - read file line by line
 * @av: array of string
 * Return: 1 if fail
 */
int read_file(FILE *file)
{
	char **av = NULL;
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;
	unsigned int n_line = 0;
	stack_t *top = NULL;

	while ((nread = getline(&line, &size, file)) != -1)
	{
		n_line++;
		av = split_string(line, " \n\t");
		if (av == NULL)
			return (EXIT_FAILURE);

		if (_strlen(av) == 2)
		{
<<<<<<< HEAD
			/*if (isdigit(av[1]))
=======
			if (error_push(av[1]) == 0)
>>>>>>> 4f8cf5dcadb3c3e6583f1ea1e5fa3f677b3d61af
				arg_push = atoi(av[1]);
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", n_line);
				free(line);
				free_pointer(av);
				free_struct(top);
				exit(EXIT_FAILURE);
			}*/
		}
		execute(&top, av, n_line);
		free_pointer(av);
	}

	free(line);
	free_struct(top);
	return (0);
}

/**
 * execute - execute function
 * @top: head of stack
 * @av: array of string
 * @n: line number
 * Return: 0 if sucess , 1 if failed
 */
int execute(stack_t **top, char **av, unsigned int n)
{
	instruction_t order[] = {
		{ "push", push },
		{ "pall", pall},
		/**
		{ "pop", pop },
		{ "add", add },
		{ "nop", nop },
		*/
		{ NULL, NULL}
	};
	int i = 0;

	while (order[i].opcode != NULL)
	{
		if (strcmp(av[0], order[i].opcode) == 0)
		{
			order[i].f(top, n);
			return (EXIT_SUCCESS);
		}
		i++;
	}


	free_stack(top);
	fprintf(stderr, "L%d: unknown instruction %s\n", n, av[0]);
	return (EXIT_FAILURE);

}


/**
 * free_struct - free stack
 * @head: head pointer
 * Return: Nothing
 */

void free_stack(stack_t **top)
{
	stack_t *temp = *top;

	while (*top)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
}

/**
 * free_struct - free the entire list
 * @head: head pointer
 * Return: Nothing
 */
void free_struct(stack_t *head)
{
	if (!head)
		return;
	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	if (!(head->next))
		free(head);
}

/**
 * free_pointer - free pointer to pointer
 * @av: pointer to pointer
 * Return: void
 */
void free_pointer(char **av)
{
	int i = 0;

	while(av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	if (av != NULL)
		free(av);
}
