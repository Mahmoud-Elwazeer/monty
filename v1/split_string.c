#include "monty.h"

/**
 * split_string - split strings
 * @str: pointer to string that will be splited
 * @delim: pointer to string that compare to split
 * Return: array of sring content new split strings
 */
char **split_string(char *str, char *delim)
{
	char **splits = NULL;
	char *split = NULL;
	int count = 0;

	splits = (char **)malloc(sizeof(char *) * 1024);
	if (splits == NULL)
	{
		free(str);
		free(splits);
		return (NULL);
	}

	split = strtok(str, delim);
	if (split == NULL)
	{
		free(str);
		free(split);
		return (NULL);
	}

	while (split != NULL)
	{
		splits[count] = split;
		count++;
		split = strtok(NULL, delim);
	}
	splits[count] = NULL;
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
