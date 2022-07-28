#include "shell.h"

/**
 * main - Initializes shell functions
 * @argc: Number of arguments passed to function
 * @argv: Array of args
 * Return: always 0
 */

/*int main(int argc, char *argv[])
{
	path_t *path;
	char **args;
	char *filepath;
	int i = 0, isKid = 1, status, lineno = 0;

	path = getpath();
	for (lineno = 1; (isKid != 0) && (argc == 1); lineno++)
	{
		wait(&status);
		args = user_console();
		if (args == NULL)
		{
			freedouble(args);
			continue;
		}
		filepath = _strdup(_which(args[0], path));
		isKid = fork();
	}
	if (isKid == -1)
		error(argv[0], lineno, args[0]);
	if (argc > 1)
	{
		args = malloc((argc - 1) * sizeof(*args));
		if (args == NULL)
		{
			free(args);
			return (0);
		}
		while (argv[i + 1] != NULL)
		{
			args[i] = _strdup(argv[i + 1]);
			i++;
		}
		filepath = _strdup(_which(args[0], path));
	}
	executer(filepath, argv[0], args, lineno);
	free(filepath);
	free_path(path);
	freedouble(args);
	return (0);
}
*/

int main(int argc, char *argv[])
{
	path_t *path;
	char **args, *filepath;
	int isKid, status;

	path = getpath();

	if (argc == 1)
		args = user_console();

	filepath = _which(args[0], path);	

	isKid = fork();
	if (isKid == -1)
		return (-1);
	if (isKid == 0)
	{
		if (execve(filepath, args, NULL) == -1)
			return (-1);
	}

	wait(&status);

	free(filepath);
	freedouble(args);	
	free_path(path);
	return (0);
}

/**
 * executer - executes files in the path
 * @filepath: filepath to execute
 * @filename: name of program in argv[0]
 *	(used for error handling)
 * @args: double array containing flags and arguments for filepath
 * @lineno: number of commands that have been entered to the shell
 *	(used for error handling)
 */

/*
void executer(char *filepath, char *filename, char **args, int lineno)
{
	if (filepath == NULL)
	{
		error(filename, lineno, args[0]);
		exit(0);
	}

	if (execve(filepath, args, NULL) == -1)
		error(filename, lineno, args[0]);
}
*/






