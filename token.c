#include "main.h"

/**
 * _strtok - Function that splits strings.
 * @str: string to be splited.
 * @delim: Separator.
 * Return: a pointer to the address of the string.
*/

char **_strtok(char *str, const char *delim)
{
	char *token;
	int i = 0, j = 0, numtok = 0;
	char **av;

	token = strtok(str, delim);

	while (token != NULL)
	{
		numtok++;
		token = strtok(NULL, delim);
	}
	numtok++;
	av = malloc(sizeof(char *) * numtok);
	if (!av)
	{
		free(str);
		return (NULL);
	}

	token = strtok(str, delim);
	while (token != NULL)
	{
		av[i] = malloc(strlen(token) + 1);
		if (av[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(av[j]);
			}
			free(av);
			free(str);
			return (NULL);
		}
			strcpy(av[i], token);
			token = strtok(NULL, delim);
			i++;
	}
		av[i] = NULL;
		return (av);
}
