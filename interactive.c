#include "main.h"

/**
 * main - open shell, project base
 * Return: int
 */

void run_interactive_mode()
{
	size_t n = 0;
	char *lineptr = NULL;
	ssize_t linecount;
	const char *delim = " \n";
	char **cmd_arguments;

	/* Creates an infinit loop*/
	while (1)
	{
		printf("hsh$ ");
		linecount = getline(&lineptr, &n, stdin);
		if (linecount == -1 || strcmp("exit\n", lineptr) == 0)
		{
			free(lineptr);
			break;
		}
		

		if (strcmp("env", lineptr) == 0)
		{
			_env();
			continue;
		}
		cmd_arguments = _strtok(lineptr, delim);
		execmd(cmd_arguments);
	}
}
