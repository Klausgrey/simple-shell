#include "main.h"

/**
 * get_location - gets the path
 * @cmd: command passed to the function
 * Return: NULL.
*/

char *get_location(char *cmd)
{
		char *path, *path_copy, *path_token, *file_path;
		int command_length, directory_length;
		struct stat buffer;

		path = getenv("PATH");
		if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(cmd);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, cmd);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}
		free(path_copy);
		if (stat(cmd, &buffer) == 0)
		{
			return (cmd);
		}

		return (NULL);
	}
return (NULL);
}
