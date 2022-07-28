#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

/**
 * struct path - struct for building the PATH
 * @directory: the string of the directory
 * @nextdir: pointer to next node
 * Return: 0
 */
typedef struct path
{
	char *directory;
	struct path *nextdir;
} path_t;

/* Environment */
char *_which(char *token, path_t *head);
char *_getenv(char *name);
int delimcount(char *buffer);
path_t *add_path_node(path_t **head, char *str);
path_t *getpath(void);

/* Strings */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *copycat(char *s1, char *s2);
int _strlen(char *);

/* Main functions */
char **user_console(void);
char **non_interactive_mode(void);
char **parse_input(char *str);
void freeargs(char **args);
void printenv(void);

/* Error and Freeing functions */
void error(char *filename, int lineno, char *argument);
#endif
