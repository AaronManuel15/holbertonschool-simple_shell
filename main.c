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

	if (isatty(STDIN_FILENO) != 0)
		args = user_console();

	while (args[i] != NULL)
	{
		printf("input: %s\n", args[i]);
		i++;
	}

	return (0);
}
