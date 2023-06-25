#include "monty.h"

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: content of argument
 * Return: 0 when success
 */
int main(int ac, char *av[])
{
	FILE *file;
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;
	stack_t *top = NULL;
	instruction_t execute;

	if (ac != 2)
	{
		printf("USAGE: monty %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &size, file)) != -1)
	{
		av = split_string(line, " \n\t");
		if (_strlen(av) == 2)
		{
			execute.opcode = "push";
			execute.f = push;
			execute.f(&top, atoi(av[1]));
		}
		else
			pall(&top);
	}
	if (line)
		free(line);

	fclose(file);
	return (0);
}
