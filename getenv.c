#include "main.h"

/**
 * _getenv - gets an env value
 * @key: string 
 * @env: list of env key pairs
 * Return: Value if exists
 */

char *_getenv(char *key, char **env)
{
        const char del[] = "=";
        int i = 0, check = 0;
        char *mytoken, *variable;

        while (env[i] != NULL)
        {
                variable = _strdup(env[i]);
                mytoken = strtok(variable, del);
                
                while (mytoken != NULL)
                {
                        if (check == 1)
                        {
                                return (mytoken);
                        }

                        if (_strcompare(key, mytoken) == 0)
                        {
                                check = 1;
                        }
                        mytoken = strtok(NULL, del);
                }
                free(variable);
                i++;
        }

        return(NULL);
}
