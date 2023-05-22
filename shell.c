#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

/*
 * main - imitates functionallity of a shell that takes commands without arguments
 * @ac: count of argumens
 * @av: list of arguments
 * Return: 0 on success, 1 when ot right count of arguments
 */

int main(int ac, char **av)
{
	size_t size = 0;
	ssize_t get = 0;
	char *input = NULL, *argv[3] = {NULL, NULL, NULL};
	int status;
	pid_t pid;

	if (ac != 1)
	{
		printf("Usage: %s\n", av[0]);
		return (1);
	}
	while (1)
	{
		printf("#cisfun$ ");
		get = size = getline(&input, &size, stdin);

		if (get == -1)
		{
			printf("\n");
			break;
		}
		if (input[size - 1] == '\n')
		{
			input[size - 1] = '\0';
			size--;
		}
		pid = fork();

		if (pid == -1)
			perror(av[0]);
		else if(pid == 0)
		{
			argv[0] = input;
			argv[1] = NULL;
			execve(input, argv, environ);
			perror(av[0]);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(input);
	return (0);
}
