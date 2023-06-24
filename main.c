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

	if (ac != 1)
	{
		printf("USAGE: monty %s", av[1]);
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	fclose(file);
	return (0);
}
