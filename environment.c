#include "shell.h"

/**
 * _getenv - gets information for what is asked for in environ
 * @name: what to look for in environ
 * Return: copy of environ item upon success. value of fail upon failure
 */

char *_getenv(char *name)
{
	int i = 0, len = _strlen(name);
	char *copy, *out;

	while (environ[i])
	{
		if (_strncmp(name, environ[i], len) == 0)
		{
			copy = _strdup(environ[i]);
			copy += ++len;
			out = _strdup(copy);
			copy -= len;
			free(copy);
			return (out);
		}
		i++;
		}
	return (NULL);
}

/**
 * add_path_node - adds a new node at the end of path_t
 * @head: pointer to head of list
 * @str: string to be duplicated
 * Return: address of new element upon success. NULL if failed.
 */

path_t *add_path_node(path_t **head, char *str)
{
	path_t *new, *ptrCopy;

	ptrCopy = *head;

	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->directory = _strdup(str);
	new->nextdir = NULL;

	if (!(*head))
		*head = new;
	else
	{
		while (ptrCopy->nextdir)
			ptrCopy = ptrCopy->nextdir;

		ptrCopy->nextdir = new;
	}
	return (*head);
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

/**
 * getpath - creates a linkedlist of each location in PATH
 * Return: head of list
 */

path_t *getpath(void)
{
	char *pathString, *token;
	path_t *head = NULL;


	pathString = _getenv("PATH");
	token = strtok(pathString, ":");
	head = add_path_node(&head, token);

	while (token)
	{
		token = strtok(NULL, ":");
		add_path_node(&head, token);
	}
	free(pathString);
	free(token);
	return (head);
}

/**
 * _which - searches is the command in token exists anywhere in linked list
 * @token: command given from user
 * @head: head of linked list
 * Return: original command with it's address or NULL
 */

char *_which(char *token, path_t *head)
{
	path_t *ptrCopy = head;
	char *command = copycat("/", token), *exec;
	struct stat st;

	exec = token;
	while (ptrCopy)
	{
		if (stat(exec, &st) == 0)
		{
			free(command);
			return (exec);
		}
		exec = copycat(ptrCopy->directory, command);
		ptrCopy = ptrCopy->nextdir;
	}
	free(command);
	free(exec);
	return (NULL);
}
