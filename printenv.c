#include "main.h"

/**
 * printenv - prints env variables
 * @env: list of env key pairs
 * Return: Nothing
 */

void printenv(char **env)
{
   int i = 0;

   while (env[i] != NULL)
   {
	_puts(env[i]);
	_puts("\n");
	i++;
   }
}
