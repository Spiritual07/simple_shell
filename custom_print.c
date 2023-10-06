#include "shell.h"

/**
 * c_print - function to print to output
 * @str: string to print
 */

void c_print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}

/**
 * _strlen - function that returns the length of a string.
 * @s: str to return it's length.
 * Return: integer (string length)
 */

int _strlen(char *s)
{
	int x;

	for (x = 0; s[x] != '\0'; x++)
	{
		x++;
	}
	return (x);
}
