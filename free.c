#include "shell.h"

/**
 * free_memory - Function to free memory allocated
 * @input: User input
 * @command: Arrays of commands
 * @com_sep: Arrays of commands
 * @inputCopy: copy of user input gotten by _strdup
 */

void free_memory(char *input, char **command, char **com_sep, char *inputCopy)
{
	if (input != NULL)
	{
    	free(input);
	}
	if (inputCopy != NULL)
	{
    	free(inputCopy);
	}
	if (com_sep != NULL)
	{
		free(com_sep);
	}
	if (command != NULL)
	{
		free(command);
	}
}

/**
 * free_com - Function to free command
 * @command: commands to be freed
 */

void free_com(char **command)
{
	free(command);
	command = NULL;
}
