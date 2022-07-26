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

	while (isKid != 0)
	{
		wait(&status);
		if (isatty(STDIN_FILENO) != 0)
			args = user_console();
		isKid = fork();
	}

	if (isKid == -1)
		perror("Error");
	
	/* Test section */
	if (isKid == 0)
	{
		while (args[i] != NULL)
		{
			printf("%s\n", args[i]);
			i++;
		}
	}
	/* End test section */
	
	free(args);
	return (0);
}
