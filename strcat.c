#include "main.h"

/**
 * _strcat - combines string
 * @s1: pointer
 * @s2: pointer
 * Return: Nothing
 */
void _strcat(char *s1, char *s2)
{
	int i, x = 0, y = 0;

	if (s1 != NULL)
	{
		x = _strlen(s1);
	}
	if (s2 != NULL)
	{
		y = _strlen(s2);
	}
	for (i = 0; i < y; i++)
	{
		s1[i + x] = s2[i];
	}
}
