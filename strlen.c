#include "main.h"

/**
 * _strlen - length of string
 * @s: pointer
 * Return: Length
 */

int _strlen(char *s)
{
	if (s[0] == '\0')
	{
		return (0);
	}
	else
	{
		return (1 + _strlen(s + 1));
	}
}
