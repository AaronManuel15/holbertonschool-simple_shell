#include "shell.h"

/**
 * main - Initializes shell functions
 * @argc: Number of arguments passed to function
 * @argv: Array of args
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	path_t *path;
	char **args;
	int i = 0, isKid = 1, status;

	path = getpath();
	while ((isKid != 0) && (argc == 1))
	{
		wait(&status);
		if (isatty(STDIN_FILENO) != 0)
			args = user_console();
		else
		{
			args = non_interactive_mode();
			args[0] = _strdup(_which(args[0], path));
			break;
		}
		args[0] = _strdup(_which(args[0], path));
		if (_strcmp(args[0], "(nil)") == 0)
		{
			perror("error");
			continue;
		}
		if (args[0] == NULL)
			continue;
		isKid = fork();
	}
	if (isKid == -1)
		perror("Error");
	if (argc > 1)
	{
		args = malloc((argc - 1) * sizeof(*args));
		if (args == NULL)
			return (0);

		while (argv[i + 1] != NULL)
		{
			args[i] = _strdup(argv[i + 1]);
			i++;
		}
		args[0] = _strdup(_which(args[0], path));
	}

	/* Test section */
	printf("Attempting to execute %s\n", args[0]);
	if (execve(args[0], args, NULL) == -1)
		perror("error");
	/* End test section */
	freeargs(args);
	return (0);
}

char **non_interactive_mode(void)
{
	char *buffer = NULL, **args;
	size_t buffsize = 0;

	getline(&buffer, &buffsize, stdin);

	args = parse_input(buffer);
	return (args);
}

void freeargs(char **args)
{
	int i;

	for (i = 0; args[i]; i++)
		free(args[i]);
	free(args);
}










