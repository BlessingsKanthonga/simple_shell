#include "main.h"

/**
 * execute - executes commands
 * @argv: list of null terminated strings
 * @env: lists of env key pairs
 * @filename: name of fil
 * Return: Nothing
 */

void execute(char **argv, char **env, char *filename)
{
	char *command = NULL, *full_command = NULL, str[] = "betty";

	if (argv)
	{
		/* get command */
		command = _strdup(argv[0]);
		if (_strcompare("env", command) == 0)
		{
			printenv(env);
		}
		else
		{
			if (_strcompare(str, command) == 0)
				full_command =_strdup("/usr/local/bin/betty");
			else
				full_command = getcommand(command, env);
                        
                        if (full_command == NULL && !isatty(fileno(stdin)))
                        {              
                                _puts(filename);
                                _puts(": 1: ");
                                _puts(argv[0]);
                                _puts(": not found\n");
                        }
                        else
                        {
				if (full_command == NULL)
                                        full_command =_strdup(command);
				/* verify if full_command is a valid executable */
				if (access(full_command, X_OK) == -1)
				{
					perror("Error:");
					free(full_command);
					free(command);
					return;
				}
        			/* execute the command wit execve */
	        		if (execve(full_command, argv, NULL) == -1)
		        	{
			        	perror("Error:");
                                }
			}
			free(full_command);
		}
                free(command);
	}
}
