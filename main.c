#include "monty.h"

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: content of argument
 * Return: 0 when success
 */
int main(int ac, char *av[])
{
	if (ac != 1)
	{
		printf("USAGE: monty %s", av[1]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
