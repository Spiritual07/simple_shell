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

	read = _getline(&input, len, inputFile);
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
	handle_comments(input);
	input[_strcspn(input, "\n")] = 0;

	return (input);
}

/**
 * tokenize - function that tokenize input
 * @input: A string containing user input
 * @delim: Delimiter to use to tokenization
 * @splitCommands: Boolean expression to split commands
 * Return: pointers to the parsed tokens from the input string.
 */

char **tokenize(char *input, char *delim, bool splitCommands)
{
	size_t size = 8;
	char **command, **temp;
	char *parsed;
	size_t index = 0;

	delim = splitCommands ? ";||&&" : TOK_DELIM;
	command = malloc(sizeof(char *) * size);
	if (command == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	parsed = c_strtok(input, delim);
	while (parsed != NULL)
	{
		if (index >= size)
		{
			temp = _realloc(command, size * sizeof(char *), sizeof(char *) * size * 2);
			if (temp == NULL)
			{
				free(command);
				perror("Memory allocation failed");
				exit(EXIT_FAILURE);
			}
			command = temp;
		}
		command[index++] = parsed;
		parsed = c_strtok(NULL, delim);
	}
	command[index] = NULL;
	return (command);
}

/**
 * executeCommand - Function to execute the command parsed
 * @command: An array of strings representing the command and its arguments.
 * @argv: An array of strings
 * @argc: Argument count
 * Return: exit status
 */

int executeCommand(char **command, int argc, char *argv[])
{
	char f_path[MAX_PATH];
	size_t f_path_size = sizeof(f_path);
	int command_found = 0, status;

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
		p_error(command[0], argc, argv);
		return (-1);
	}
	status = execute_com(command, argc, f_path, argv);

	return (status);
}

/**
 * handle_comments - Function that handle comments in a line of commands
 * @str: the string to remove any comments that start with the # character
 */

void handle_comments(char *str)
{
	char *comment_start;

	comment_start = _strchr(str, '#');
	if (comment_start != NULL)
	{
		*comment_start = '\0';
	}
}

