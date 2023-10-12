#include "shell.h"

/**
 * _strpbrk -  Function that searches a string for any of a set of bytes.
 * @str: Input string
 * @accept: Input string
 * Return: Pointer to the byte in s that matches one of
 * the bytes in accept, or NULL if no such byte is found
 */

char *_strpbrk(char *str, const char *accept)
{
	int x, y;

	/* loop through the characters in s */
	for (x = 0; str[x] != '\0'; x++)
	{
		/* for each character in s, loop through characters in accept */
		for (y = 0; accept[y] != '\0'; y++)
		{
			/* compare characters in s and accept */
			if (str[x] == accept[y])
			{
				return (&str[x]); /* return pointer to the matched character in s */
			}
		}
	}
	return ('\0'); /* return NULL if no match is found */
}

/**
 * _strspn -  function that gets the length of a prefix substring.
 * @str: string to be scanned
 * @accept: string containing characters to be matached
 * Return: number of bytes in the initial segment of s
 */

unsigned int _strspn(char *str, const char *accept)
{
/* initializes a counter to keep track of the number of matching characters. */
	unsigned int count = 0;
	int x, y;

/* loop through string s until it hits NULL character or space */
	for (x = 0; str[x] != '\0'; x++)
	{
/* loop over string accept until it hits NUll character */
		for (y = 0; accept[y] != '\0'; y++)
		{
			if (str[x] == accept[y]) /* check for match between s and accept */
			{
				count++; /* count incremented */
/* break loop, move to next character in s when matching character is found */
				break;
			}
		}
		if (str[x] != accept[y])
			break;
	}
	return (count);
}
