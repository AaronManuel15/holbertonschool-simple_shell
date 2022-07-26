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

	write(STDIN_FILENO, "($) ", 4);
	count = getline(&buffer, &buffsize, stdin);

	if (count == EOF)
	{
		write(0, "exit\n", 5);
		exit(0);
	}

	args = parse_input(buffer);

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args[0]);
		free(args);
		write(1, "exit\n", 5);
		exit(0);
	}
	if (_strcmp(args[0], "env") == 0)
	{
		printenv();
		return (NULL);
	}

	return (args);
}

/**
 * parse_input - cleans input into usable arguments
 * @str: input string
 * Return: parsed string
 */

char **parse_input(char *str)
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

	tokens = malloc(sizeof(*tokens) * count);

	count = 0;
	token = strtok(strCpy, " ");
	while (token != NULL)
	{
		tokens[count] = _strdup(token);
		token = strtok(NULL, " ");
		count++;
	}
	free(str);
	free(strCpy);
	return (tokens);
}

void printenv()
{
	int i, len;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
	}
}
