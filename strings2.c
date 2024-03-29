#include "shell.h"

/**
 * *_strdup - function that returns a pointer to a newly allocated
 * space in memory, which contains a copy of the string given as a parameter.
 * @str: string give that is to be copied
 * Return: pointer to the coppied string, NULL if insufficient memory available
 */

char *_strdup(char *str)
{
	int x, y;
	char *cpy;

	if (str == 0)
	{
		/* return NULL if string is empty */
		return (NULL);
	}
	/* Check for length of original string */
	for (x = 0; str[x] != '\0'; x++)
		;
	/* allocate memory to hold duplicate string */
	cpy = (char *)malloc(sizeof(char) * (x + 1));

	/* return NULL if duplicate string is empty */
	if (cpy == NULL)
	{
		return (NULL);
	}
	/* duplicate string by copying characters from given string */
	/* to newly allocated memory using for loop */
	for (y = 0; y <= x; y++)
	{
		cpy[y] = str[y];
	}
	return (cpy); /* return duplicate string */
}

/**
 * _atoi - function that converts string to an integer
 * @str: Number of string to be converted
 * Return: integer from the conversion
 */

int _atoi(char *str)
{
	int sign = 1, x;
	unsigned int num_val = 0;
	char null_flag = 0;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] == '-')
			sign = sign * -1;

		if (str[x] >= '0' && str[x] <= '9')
		{
			null_flag = 1;
			num_val = num_val * 10 + (str[x] - '0');
		}

		else if (null_flag)
			break;
	}

	if (sign < 0)
		num_val = (-num_val);

	return (num_val);
}

/**
 * _memcpy -  function that copies memory area.
 * @dest: destination string to copy to
 * @src: source string to copy from
 * @n: number of bytes
 * Return: pointer to dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;
	unsigned int x;

	for (x = 0; x < n; x++)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (p);
}

/**
 * _itoa - Function that convert integer to string
 * @n: input integer
 * Return: Pointer to the converted string
 */

char *_itoa(unsigned int n)
{
	unsigned int n_copy = n;
	int len = 0, x;
	char *str;

	while (n_copy > 0)
	{
		n_copy = n_copy / 10;
		len++;
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str[len] = '\0';
	for (x = 0; len > 0; x++, len--)
	{
		str[x] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

/**
 * _strchr - this function locates a character in string
 * @str: the pointer
 * @c: the character to locate
 * Return: S or NULL
 */

char *_strchr(const char *str, char c)
{
	int x;

	for (x = 0; str[x] != '\0'; x++)
	{
		if (str[x] == c)
			return ((char *) &str[x]);
	}
	if (str[x] == c)
		return ((char *) &str[x]);
	return (NULL);
}
