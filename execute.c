#include "main.h"

/**
 * execmd - executes the command
 * @argv: argument vector
 * Return: void (nothing)
*/

int execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		command = argv[0];
		actual_command = get_location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	}
	return (status);
}
