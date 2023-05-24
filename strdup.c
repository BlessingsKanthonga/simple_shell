#include "main.h"

/**
 * _strdup - returns duplicate of string
 * @str: pointer
 * Return: Pointer
 */
char *_strdup(char *str)
{
	char *null = NULL;
	char *p;
	int i, x;

	if (str == NULL)
	{
		return (null);
	}
	x = _strlen(str);
	p = malloc(sizeof(char) * x + 1);
	if (p == NULL)
	{
		return (null);
	}
	for (i = 0; i < x; i++)
	{
		p[i] = str[i];
	}
	p[x] = '\0';
	return (p);
}
