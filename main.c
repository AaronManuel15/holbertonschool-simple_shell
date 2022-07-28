#include "shell.h"

/**
 * main - runs our simple shell
 * @argc: number of argments given to shell
 * @argv: the value of commands given to shell
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	path_t *path;
	char **args, *filepath;
	int i;

	path = getpath();

	if (argc == 1)
	{
		args = user_console();
		if (args == NULL)
		{
			free_path(path);
			return (0);
		}
	}

	if (argc != 1)
	{
		args = malloc(sizeof(*args) * argc);
		if (args == NULL)
			return (-1);
		i = 0;
		while (argv[i + 1] != NULL)
		{
			args[i] = _strdup(argv[i + 1]);
			i++;
		}
		args[i] = NULL;
	}

	filepath = _which(args[0], path);
	if (filepath)
	{
		if (execve(filepath, args, NULL) == -1)
		{
			perror("error");
			return (-1);
		}
	}

	free(filepath);
	freedouble(args);
	free_path(path);
	return (0);
}

