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

/**
 * _strdup - returns a pointer to a copy of a string
 * @str: string to be copied
 * Return: Pointer to str copy, or NULL if error
 */

char *_strdup(char *str)
{
	char *cpy;
	int i, len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	cpy = malloc(len + 1);
	if (cpy == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		cpy[i] = str[i];
	cpy[i] = '\0';

	return (cpy);
}

/**
 * _strlen - returns the length of a string
 * @s: char
 * Return: string length
 */

int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * copycat - concatenates two strings into a new string
 * @s1: First string to concatenate
 * @s2: Second string to concatenate
 * Return: Pointer to new string
 */

char *copycat(char *s1, char *s2)
{
	int len1, len2, i, j;
	char *newStr;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = _strlen(s1);
	len2 = _strlen(s2);

	newStr = malloc(sizeof(char) * (len1 + len2) + 1);

	for (i = 0; s1[i]; i++)
		newStr[i] = s1[i];
	for (j = 0; s2[j]; j++, i++)
		newStr[i] = s2[j];
	newStr[i] = '\0';

	return (newStr);
}
