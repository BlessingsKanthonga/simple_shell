#include "main.h"

/**
 * main - runs a customized shell
 * @argc: number of args
 * @argv: arg values
 * @env: list of env key pairs
 * Return: Status
 */
int main(int argc, char **argv, char **env)
{
	pid_t child_pid;
	int status;
	char *buffer = NULL, *buffer_copy = NULL, *filename;
	size_t bufsize = 0, read_chars, check = -1;
	(void) argc;

        filename = _strdup(argv[0]);
	while (1)
	{
		_puts("($) ");
		read_chars = getline(&buffer, &bufsize, stdin);
		if (read_chars == check)
			return (-1);
		if (_strcompare("exit\n", buffer) == 0 || _strcompare("exit", buffer) == 0)
		{
			exit(3);
		}
		buffer_copy = malloc(sizeof(char) * read_chars);
		if (buffer_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		_strcpy(buffer_copy, buffer);
		argv = getargs(buffer, buffer_copy);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
			execute(argv, env, filename);
		else
			wait(&status);
	}
	free(argv);
	free(buffer);
	free(buffer_copy);
	return (0);
}
