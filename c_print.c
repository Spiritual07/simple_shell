#include "shell.h"

/**
 * c_print - function to print to output
 * @str: string to print
 */

void c_print(const char *str)
{
	write(STDOUT_FILEOUT, &str, strlen(str));
}
