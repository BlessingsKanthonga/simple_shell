#include "main.h"

/**
 * _puts - swaps two numbers
 * @s: pointer
 * Return: Nothing
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
}
