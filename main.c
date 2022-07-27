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
	char *filepath;
	int i = 0, isKid = 1, status, lineno = 0;

	path = getpath();
	for (lineno = 1; (isKid != 0) && (argc == 1); lineno++)
	{
		wait(&status);
		if (isatty(STDIN_FILENO) != 0)
			args = user_console();
		if (isatty(STDIN_FILENO) == 0)
		{
			args = non_interactive_mode();
			filepath = _strdup(_which(args[0], path));
			break;
		}
		if (args == NULL)
			continue;
		filepath = _strdup(_which(args[0], path));
		isKid = fork();
	}
	if (isKid == -1)
		error(argv[0], lineno, args[0]);
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
		filepath = _strdup(_which(args[0], path));
	}

	executer(filepath, argv[0], args, lineno);

	free(filepath);
	freedouble(args);
	return (0);
}

void executer(char *filepath, char *filename, char **args, int lineno)
{
	if (filepath == NULL)
	{
		error(filename, lineno, args[0]);
		exit(0);
	}

	printf("Attempting to execute %s\n", args[0]);
	if (execve(filepath, args, NULL) == -1)
		error(filename, lineno, args[0]);
}

char **non_interactive_mode(void)
{
	char *buffer = NULL, **args;
	size_t buffsize = 0;

	getline(&buffer, &buffsize, stdin);

	args = parse_user_input(buffer);

	return (args);
}










