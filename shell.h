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

typedef struct path
{
	char *directory;
	struct path *nextdir;
} path_t;

/* Environment */
char *_which(char *);
char *_getenv(const char *name);
int delimcount(char *buffer);
path_t *add_path_node(path_t **head, const char *str);
path_t *getpath(void);

/* Strings */
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *str);
char *copycat(char *s1, char *s2);
int _strlen(char *);

/* Console functions */
char **user_console(void);
char **parse_input(char *str);

#endif
