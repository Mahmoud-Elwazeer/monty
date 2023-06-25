#include "monty.h"

/**
 * error_push - handle error of push
 * @av: pointer to string
 * Return: 0 when sunccess or -1 is fail
 */
int error_push(char *av)
{
	int i;

	for (i = 0; av[i] != '\0'; i++)
	{
		if (av[i] >= '0' && av[i] <= '9')
			continue;
		else
			return (-1);
	}
	return (0);
}
