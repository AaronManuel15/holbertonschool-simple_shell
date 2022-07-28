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

/* Environment file */
char *_which(char *token, path_t *head);
char *_getenv(char *name);
int delimcount(char *buffer);
path_t *add_path_node(path_t **head, char *str);
path_t *getpath(void);

/* Strings file */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *copycat(char *s1, char *s2);
int _strlen(char *);

/* Main file */
void printenv(void);
void executer(char *filepath, char *filename, char **args, int lineno);

/* Console file */
char **user_console(void);
char **parse_user_input(char *str);
void printenv(void);
char **built_ins(char **args);

/* Error and Free file */
void error(char *filename, int lineno, char *argument);
char *intstr(int num);
void freedouble(char **arr);
void free_path(path_t *head);

#endif
