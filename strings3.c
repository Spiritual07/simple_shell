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

/**
 * _strcat - function that concatenates two strings
 * @dest: dest string
 * @src: src string
 * Return: Pointer to resulting string dest.
 */

char *_strcat(char *dest, const char *src)
{
	char *p = dest;

	while (*dest)
		dest++;

	while (*src)
		*dest++ = *src++;

	*dest = '\0';

	return (p);
}

/**
 * _strncmp - Function that compares n bytes of characrers of two strings
 * @str1: Input string 1
 * @str2: Input string 2
 * @n: Number of bytes
 * Return: 0 (success)
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	while (n-- > 0)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		else if (*str1 == '\0')
		{
			break;
		}
		str1++, str2++;
	}
	return (0);
}

/**
 * _strcpy - function that copies the string pointed to
 * by src, including the terminating null byte (\0),
 * to the buffer pointed to by dest.
 * @dest: destination of string
 * @src: source of string
 * Return: pointer to dest.
 */

char *_strcpy(char *dest, const char *src)
{
	char *p = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';

	return (p);
}

