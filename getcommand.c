#include "main.h"

/**
 * getcommand - generates path of command
 * @command: pointer
 * @env: list of env key pairs
 * Return: Full path of command
 */
char *getcommand(char *command, char **env)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len, i, dir_len;
	struct stat st = {0};

	path = _getenv("PATH", env);
	if (path != NULL)
	{
		path_copy = _strdup(path);
		command_len = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			dir_len = _strlen(path_token);
			file_path = malloc(command_len + dir_len + 2);

			if (file_path != NULL)
			{
				for (i = 0; i < command_len + dir_len + 2; i++)
					file_path[i] = '\0';
			}
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &st) == 0)
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
		if (stat(command, &st) == 0)
			return (command);
	}
	return (NULL);
}
