#include "main.h"

/**
 * _strcpy - concantenate strings
 * @dest: pointer
 * @src: pointer
 * Return: Copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, n;

	n = _strlen(src);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
