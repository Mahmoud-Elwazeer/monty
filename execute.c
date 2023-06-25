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

	while ((nread = getline(&line, &size, file)) != -1)
	{
		av = split_string(line, " \n\t");
		execute(av, n_line);
		if (_strlen(av) == 2)
		{
			printf("y = %d\n", atoi(av[1]));
			arg_push = atoi(av[1]);
		}
		n_line++;
	}

	free(line);
}

/**
 * execute - execute function
 * @av: array of string
 * @n: line number
 * Return: void
 */
void execute(char **av, unsigned int n)
{
	stack_t *top = NULL;
	instruction_t order;

	order.opcode = av[0];
	order.f = push;
	order.f(&top, n);
	pall(&top);

}
