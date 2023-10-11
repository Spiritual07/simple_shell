#include "shell.h"

/**
 * _strncat - function that concatenates two strings up to n characters.
 * @dest: Base string
 * @src: string to be append
 * @n: maximum number of characters to be taken from the src string
 * Return: point to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int x;
	int src_len = 0;
	char *p = dest;
	char *s = src;

	/* find the length of the src string */
	while (*src)
	{
		src_len++;
		src++;
	}
	/* find the end of the dest string */
	while (*dest)
	{
		dest++;
	}
	/* limit character to be appended to src string length */
	if (n > src_len)
	{
		n = src_len;
	}
	/* src pointer is reset to point back to the start of */
	/* the src string using the previously stored pointer s. */
	src = s;

	/* append characters from src string to dest string */
	for (x = 0; x < n; x++)
	{
		*dest++ = *src++;
	}
	/* NULL terminate dest string */
	*dest = '\0';

	return (p);

}

/**
 * _strncpy - function that copies a string
 * @dest: base string
 * @src: string to copy from
 * @n: number of characters.
 * Return: dest
 */

OB
char *_strncpy(char *dest, char *src, int n)
{
	int x;

	/* Loop over the first 'n' characters of 'src' */
	for (x = 0; x < n && src[x] != '\0'; x++)
	{
		dest[x] = src[x]; /* Copy each character from 'src' to 'dest' */
	}
	while (x < n)
	{
		dest[x] = '\0'; /* Fill the rest of 'dest' with null characters ('\0') */
		x++;
	}

	return (dest); /* return dest string */
}

/**
 * _strcmp - function that compares two strings.
 * @str1: string 1
 * @str2: string 2
 * Return: s1 - s2
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 & *str2)
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++, str2++;OA
	}
	return (*str1 - *str2);
}

/**
 * _strcspn - function that get length of a prefix substring
 * @str: input string 1
 * @reject: input string 2
 * Return: returns the number of bytes in the initial segment of
 * str which are not in the string reject.
 */

int _strcspn(char *str, char *reject)
{
	int count = 0, x, y;

	for (x = 0; str[x] != '\0'; x++)
	{
		for (y = 0; reject[y] != '\0'; y++)
		{

			if (str[x] == reject[y])
			{
				return (count);
			}
		}
		count++;
	}
	return (count);
}

/**
 * _strlen - function that returns the length of a string.
 * @str: str to return it's length.
 * Return: integer (string length)
 */

int _strlen(char *str)
{
	int x, count = 0;

	for (x = 0; str[x] != '\0'; x++)
	{
		count++;
	}
	return (count);
	OB
}
