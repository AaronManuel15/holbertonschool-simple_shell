#include "shell.h"

/**
 * error - builds error string to print to stdout
 * @filename: name of executable
 * @lineno: number of iterations through executable
 * @argument: command passed to executable that failed
 * Return: nothing
 */
void error(char *filename, int lineno, char *argument)
{
	char *errorStr;
	char *num = intstr(lineno);

	errorStr = copycat(filename, ": ");
	errorStr = copycat(errorStr, num);
	errorStr = copycat(errorStr, ": ");
	errorStr = copycat(errorStr, argument);

	perror(errorStr);
}

/**
 * intstr - converts an integer to a string
 * @num: input int
 * Return: pointer to str
 */

char *intstr(int num)
{
	int len = 1, i = 1, j;
	char *temp, *output;

	while (num / i >= 10)
	{
		i *= 10;
		len++;
	}

	temp = malloc(sizeof(char) * len);
	if (temp == NULL)
	{
		free(temp);
		exit(-1);
	}
	for (i = 0; i < len; i++)
	{
		temp[i] = (num % 10) + '0';
		num /= 10;
	}
	output = malloc(sizeof(*temp));
	for (i -= 1, j = 0; i >= 0; i--, j++)
		output[j] = temp[i];

	free(temp);
	return (output);
}

/**
 * freedouble - frees a 2d array
 * @arr: array to free
 */

void freedouble(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(args[i]);
	free(args);
}
