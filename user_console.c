#include "shell.h"

/**
 * user_console - Creates console for user input
 * Return: Pointer string of user input args
 */

char **user_console(void)
{
	char *buffer = NULL, **args;
	size_t buffsize = 0;
	int count;

	if (isatty(STDIN_FILENO) != 0)
		write(STDIN_FILENO, "($) ", 4);

	count = getline(&buffer, &buffsize, stdin);
	if (count == EOF)
	{
		if (isatty(STDIN_FILENO) != 0)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", 1);
		}
		exit(0);
	}
	if (_strcmp(buffer, "\n") == 0)
	{
		free(buffer);
		return (NULL);
	}
	args = parse_user_input(buffer);
/*	args = built_ins(args);
*/
	return (args);
}

/**
 * parse_user_input - cleans input into usable arguments
 * @str: input string
 * Return: parsed string
 */

char **parse_user_input(char *str)
{
	char **tokens, *token;
	char *strCpy = _strdup(str);
	int count = 0, i = 0;

	while (str[i])
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			strCpy[i] = '\0';
		}
		i++;
	}
	token = strtok(str, " ");
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	tokens = malloc(sizeof(*tokens) * (count + 1));
	if (!tokens)
	{
		free(tokens);
		exit(1);
	}
	count = 0;
	token = strtok(strCpy, " ");
	while (token != NULL)
	{
		tokens[count] = _strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	tokens[count] = NULL;

	free(str);
	free(strCpy);
	free(token);
	return (tokens);
}

/**
 * built_ins - built-in commands that do not exist in the path
 * @args: argument to check for built-ins
 * Return: NULL if built in found, else argument pointer
 */

char **built_ins(char **args)
{
	if (args == NULL)
		return (NULL);

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args[0]);
		free(args);
		exit(0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		free(args[0]);
		free(args);
		printenv();
		return (NULL);
	}

	return (args);
}

/**
 * printenv - prints current environment when called
 */

void printenv(void)
{
	int i, len;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}
