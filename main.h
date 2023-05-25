#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int _putchar(char c);
char *_strdup(char *str);
void _strcat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_getenv(char *key, char **env);
int _strcompare(char *s1, char *s2);
char *getcommand(char *command, char **env);
void execute(char **argv, char **env, char *filename);
char **getargs(char *buffer, char *buffer_copy);
void printenv(char **env);
void _puts(char *s);

#endif /* MAIN_H */
