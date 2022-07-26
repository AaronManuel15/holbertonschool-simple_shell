#include "shell.h"

/**
 * main - Initializes shell functions
 * @argc: Number of arguments passed to function
 * @argv: Array of args
 * @env: Array of environmental variables
 * Return: always 0
 */

int main(int argc, char *argv[], char **env)
{
	char **args;
	int i = 0;
	int isKid = 1, status;

	while ((isKid != 0) && (argc == 1))
	{
		wait(&status);
		if (isatty(STDIN_FILENO) != 0)
			args = user_console();
		else
		{
			args = non_interactive_mode();
			break;
		}
			
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
	}

	
	/* Test section */
	i = 0;
	while (i < 2)
	{
		printf("%s\n", args[i]);
		i++;
	}
	/* End test section */
	
	freeargs(args);
	return (0);
}

char **non_interactive_mode(void)
{
	char *buffer = NULL, **args;
	ssize_t buffsize = 0;

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










