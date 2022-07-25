#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @s1: String input 1
 * @s2: String input 2
 * Return: int difference between s1 and s2
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (diff);
}

/**
 * _strncmp - compares two strings to a certain number of bytes
 * @s1: String 1
 * @s2: String 2
 * @n: number of bytes to compare
 * Return: Difference between s1 and s2
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i, diff = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";


	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
	}
	return (diff);
}
