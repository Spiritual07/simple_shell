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
 * _realloc - Function to reallocate memory
 * @ptr: A pointer to the existing memory block that you want to resize.
 * @newSize: n unsigned integer representing the
 * desired new size for the memory block.
 * Return: pointer to the new memory block
 */

void *_realloc(void *ptr, unsigned int newSize)
{
	void *newptr;
	size_t oldSize;

	if (ptr == NULL)
		return (malloc(newSize));

	if (newSize == 0)
	{
		free(ptr);
		return (NULL);
	}
	/* Get the size of the old block of memory */
	oldSize = *((size_t *)ptr - 1);
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
