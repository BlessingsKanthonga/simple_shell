#include "main.h"

/**
 * getargs - derives arguments
 * @buffer: input text stream
 * @buffer_copy: copy of input text stream
 * Return: List of executable args
 */
char **getargs(char *buffer, char *buffer_copy)
{
	int len, i, tokens_num = 0;
	const char del[] = " \n";
	char *token, **argv;

	/* count number of words */
	token = strtok(buffer, del);
	while (token != NULL)
	{
		tokens_num++;
		token = strtok(NULL, del);
	}
	/* For NULL value */
	tokens_num++;

	/* add commands and arguments to argv */
	argv = malloc(sizeof(char *) * (tokens_num + 1));
	token = strtok(buffer_copy, del);
	for (i = 0; token != NULL; i++)
	{
		len = _strlen(token);
		argv[i] = malloc(sizeof(char) * (len + 1));
		argv[i] = _strdup(token);
	/*	_strcpy(argv[i], token);*/
		token = strtok(NULL, del);
	}
	argv[i] = NULL;
	return (argv);
}
