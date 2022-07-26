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

	errorStr = copycat(filename, ": ");
	errorStr = copycat(errorStr, lineno);
	errorStr = copycat(errorStr, ": ");
	errorStr = copycat(errorStr, argument);

	perror(errorStr);
}
