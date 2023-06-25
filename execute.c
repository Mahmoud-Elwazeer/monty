#include "monty.h"

int arg_push;


/**
 * read_file - read file line by line
 * @av: array of string
 * Return: void
 */
void read_file(FILE *file, char **av)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;
	unsigned int n_line = 0;
	stack_t **top = NULL;

	while ((nread = getline(&line, &size, file)) != -1)
	{
		n_line++;
		free(av[0]);
		free(av[1]);
		av[0] = (char *)malloc(sizeof(char) * 1024);
		av[1] = (char *)malloc(sizeof(char) * 1024);
		av = split_string(line, " \n\t");
		if (_strlen(av) == 2)
			arg_push = atoi(av[1]);
		execute(&top, av, n_line);
	}

	free(line);
	/*free_stack(&top);*/
}

/**
 * execute - execute function
 * @top: head of stack
 * @av: array of string
 * @n: line number
 * Return: void
 */
void execute(stack_t **top, char **av, unsigned int n)
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
			break;
		}
		i++;
	}

	free_stack(top);

}


/**
 * free_struct - free stack
 * @head: head pointer
 * Return: Nothing
 */
void free_stack(stack_t **top)
{
	stack_t *temp = *top;

	while (temp)
	{
		temp = (*top)->next;
		free(*top);
		*top = temp;
	}
}
