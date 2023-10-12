#include "shell.h"

/**
 * errorMsg - Function to display error like original shell
 * @input: User input
 * @count: loop counter
 * @av: Strings of arguments
 */

void errorMsg(char *input, int count, char *av[])
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

