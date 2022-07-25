#include "shell.h"

/**
 * _getenv - gets information for what is asked for in environ
 * @name: what to look for in environ
 * Return: copy of environ item upon success. value of fail upon failure
 */

char *_getenv(const char *name)
{
	int i = 0, len = strlen(name);
	char *fail = "(null)", *copy;

	while (environ[i])
	{
		if (strncmp(name, environ[i], len) == 0)
		{
			copy = strdup(environ[i]);
			copy += ++len;
			return (copy);
		}
		i++;
		}
	return (fail);
}

/**
 * add_path_node - adds a new node at the end of path_t
 * @head: pointer to head of list
 * @str: string to be duplicated
 * Return: address of new element upon success. NULL if failed.
 */

path_t *add_path_node(path_t **head, const char *str)
{
	path_t *new, *ptrCopy;

	ptrCopy = *head;

	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->directory = strdup(str);
	new->nextdir = NULL;

	if (!(*head))
		*head = new;
	else
	{
		while (ptrCopy->nextdir)
			ptrCopy = ptrCopy->nextdir;

		ptrCopy->nextdir = new;
	}
	return (head);
}

/**
 * delimcount - counts the amount of fields via delimeters
 * @buffer: buffer to be checked for fields and delims
 * Return: number of fields
 */

int delimcount(char *buffer)
{
	int i = 0, count = 0;

	while (buffer[i])
	{
		if (buffer[i] == ' ')
			count++;
		if (buffer[i] == '\n')
			buffer[i] = '\0';
		i++;
	}
	count += 2;
	return (count);
}
