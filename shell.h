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

char *_which(char *);
char *_getenv(const char *name);
int delimcount(char *buffer);
path_t *add_path_node(path_t **head, const char *str);

int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);

#endif
