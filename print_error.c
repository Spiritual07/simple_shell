#include "shell.h"

/**
 * p_error - Function to display error like original shell
 * @input: User input
 * @count: loop counter
 * @av: Strings of arguments
 */

void p_error(char *input, int count, char *av[])
{
	char *msg = _itoa(count);

	c_print(av[0]);
	c_print(": ");
	c_print(msg);
	c_print(": ");
	c_print(input);
	c_print(": not found\n");

	free(msg);
}

/**
 * print_error - Function to print error message
 * @path: path entered
 */

void print_error(char *path)
{
	char *error_start = "./hsh: 1: cd: can't cd to ";
	char *error_end = "\n";
	char error_msg[BUFFERSIZE];
	int x;

	for (x = 0; error_start[x] != '\0'; x++)
	{
		error_msg[x] = error_start[x];
	}
	for (x = 0; path[x] != '\0'; x++)
	{
		error_msg[x + _strlen(error_start)] = path[x];
	}
	error_msg[_strlen(error_start) + _strlen(path)] = error_end[0];
	error_msg[_strlen(error_start) + _strlen(path) + 1] = '\0';

	write(STDERR_FILENO, error_msg, _strlen(error_msg));
}


