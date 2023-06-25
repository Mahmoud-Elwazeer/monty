#include "monty.h"

/**
 * split_string - split strings
 * @str: pointer to string that will be splited
 * @delim: pointer to string that compare to split
 * Return: array of sring content new split strings
 */
char **split_string(char *str, char *delim)
{
	char **splits;
	char *split;
	int count = 0;

	splits = (char **)malloc(sizeof(char *) * 1024);
	if (splits == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	split = strtok(str, delim);
	while (split != NULL)
	{
		splits[count++] = strdup(split);
		split = strtok(NULL, delim);
	}
	splits[count] = NULL;
	free(split);
	return (splits);
}

/**
 * _strlen : len of array of string
 * @av: array of string
 * Return: len of array
 */
int _strlen(char **av)
{
	int i = 0;

	while (av[i] != NULL)
		i++;

	return (i);
}
