#include "shell.h"

/**
 * c_print - function to print to output
 * @str: string to print
 */

void c_print(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
