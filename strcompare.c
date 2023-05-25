#include "main.h"

/**
 * _strcompare - length of string
 * @s1: first string
 * @s2: second string
 * Return: Length
 */
int _strcompare(char *s1, char *s2)
{
	int i = 0;

	if ((s1 == NULL) && (s2 == NULL))
		return (0);
	else if ((s1 == NULL) || (s2 == NULL))
		return (1);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' || s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

