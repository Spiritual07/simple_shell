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
 * _print - function to print to standard error
 * @str: string to print
 */

void _print(char *str)
{
	write(STDERR_FILENO, str, _strlen(str));
}

/**
 * _realloc - Function to reallocate memory
 * @ptr: A pointer to the existing memory block that you want to resize.
 * @newSize: Desired new size for the memory block.
 * @oldSize: Old size of memory
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, size_t oldSize, size_t newSize)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(newSize));

	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (newSize == oldSize)
		return (ptr);

	newptr = malloc(newSize);
	if (newptr == NULL)
		return (NULL);

	if (newSize < oldSize)
		_memcpy(newptr, ptr, newSize);
	else
		_memcpy(newptr, ptr, oldSize);

	free(ptr);
	return (newptr);
}

/**
 * print_num - Function that prints an integer.
 * @n: Integer to be print
 * Return: Variable that keep track of character print count
 */

int print_num(int n)
{
	/* declare a varible to keep track of characters counts */
	int x = 0;

/* check if n is greater or equal to zero */
	if (n >= 10)
	/* call print_number function to print the remaining digits */
	x = x + print_num(n / 10);

	_putchar(n % 10 + '0'); /* print the last digit number */
	x++; /* increament counter */

	return (x);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and err no is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
