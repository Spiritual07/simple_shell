#include "shell.h"

/**
 * processInput - Function to process user input
 * @len: A pointer to a size_t variable, which
 * will be used to store the length of the input.
 * @inputFile: A pointer to a FILE object, representing the input file
 * from which the function will read lines of text.
 * Return: processed user input is returned as a character pointer.
 */

char *processInput(size_t *len, FILE *inputFile)
{
	char *input = NULL;
	ssize_t read;

	read = getline(&input, len, inputFile);
	if (read == -1)
	{
		if (feof(inputFile))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline failed");
			exit(EXIT_FAILURE);
		}
	}
	input[_strcspn(input, "\n")] = 0;

	return (input);
}

/**
 * tokenize - function that tokenize input
 * @input: A string containing user input
 * Return: pointers to the parsed tokens from the input string.
 */

char **tokenize(char *input)
{
	size_t size = 8;
	char **command, **temp;
	char *delim = " ", *parsed;
	size_t index = 0;

	command = malloc(sizeof(char *) * size);
	if (command == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	parsed = strtok(input, delim);
	while (parsed != NULL)
	{
		if (index >= size)
		{
			size = size + size;
			temp = realloc(command, sizeof(char *) * size);
			if (temp == NULL)
			{
				free(command);
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			command = temp;
		}
		command[index++] = parsed;
		parsed = strtok(NULL, delim);
	}
	command[index] = NULL;
	return (command);
}

/**
 * executeCommand - Function to execute the command parsed
 * @command: An array of strings representing the command and its arguments.
 * @environ: An array of strings representing the environment variables.
 */


void executeCommand(char **command, char **environ, char *argv[])
{
	char f_path[255];
	size_t f_path_size = sizeof(f_path);
	int command_found = 0;

	command_found = check_cwd(command, f_path, f_path_size);

	/* If the command is not an absolute path and it's not in the */
	/* current working directory, search the PATH directories */
	if (!command_found && command[0][0] != '/')
	{
		command_found = search_path_dirs(command, f_path, f_path_size);
	}
	else if (!command_found)
	{
		command_found = handle_abs_path(command, f_path, f_path_size);
	}

	/* Check if the command exists before calling fork() */
	if (!command_found)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
		return;
	}
	execute_com(command, environ, f_path, argv);
}

