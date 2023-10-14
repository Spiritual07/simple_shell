#include "shell.h"

/**
 * open_input_file - Function to open the input file
 * @argc: argument counts
 * @argv: An array of strings representing the command-line arguments.
 * Return: Pointer to opened file
 */

FILE *open_input_file(int argc, char *argv[])
{
	FILE *inputFile = stdin;

	if (argc > 1)
	{
		inputFile = fopen(argv[1], "r");
		if (inputFile == NULL)
		{
			perror("Error opening input file");
			exit(EXIT_FAILURE);
		}
	}
	return (inputFile);
}

/**
 * handle_env_command - Function to handle 'env' command
 * @env: An array of strings representing environment variables.
 */

void handle_env_command(char **env)
{
	int x = 0;

	while (env[x])
	{
		c_print(env[x]);
		c_print("\n");
		x++;
	}
}

/**
 * handle_exit_com - Function to handle exit command
 * @input: Pointer that will be used to store the user input.
 * @command: An array of strings representing the command and its arguments.
 * @inputFile:  A pointer to a FILE object, representing the input
 * file from which the function will read lines of text.
 * @com_sep: Array of strings representing commands
 * @inputCopy: Copy of input
 * @status: number to exit with
 */

void handle_exit_com(char *input, char **command, char **com_sep,
				char *inputCopy, FILE *inputFile, int status)
{
	free_memory(input, command, com_sep, inputCopy);

	if (inputFile != stdin)
	{
		fclose(inputFile);
	}
	exit(status);
}

/**
 * main - Simple shell implementation
 * @argc: Argument counts
 * @argv: An array of strings representing the command-line arguments.
 * @env: An array of strings representing environment variables.
 * Return: 0 (success)
 */

int main(int argc, char *argv[], char **env)
{
	FILE *inputFile = open_input_file(argc, argv);
	char **command, **com_sep;
	char *input = NULL, *inputCopy;
	size_t len = 0, x;
	int status = 0;

	signal(SIGINT, handle_sigint);
	while (argc)
	{
		if (isatty(STDIN_FILENO))
			c_print("cisfun($) ");
		input = processInput(&len, inputFile);
		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}
		inputCopy = _strdup(input);
		com_sep = tokenize(inputCopy, "|;", true);
		for (x = 0; com_sep[x] != NULL; x++)
		{
			command = tokenize(com_sep[x], TOK_DELIM, false);
			if (command == NULL || command[0] == NULL)
			{
				continue;
			}
			if (_strcmp(command[0], "env") == 0)
			{
				handle_env_command(env);
				continue;
			}
			if (_strcmp(command[0], "cd") == 0)
			{
				cd(command[1]);
				continue;
			}
			if (_strcmp(command[0], "exit") == 0)
			{
				status = command[1] ? _atoi(command[1]) : EXIT_SUCCESS;
				handle_exit_com(input, command, com_sep, inputCopy, inputFile, status);
			}
			if (_strcmp(command[0], "echo") == 0)
			{
				echo_arg(command, status);
				continue;
			}
			status = executeCommand(command, argc, argv);
			free(command);
			command = NULL;
		}
		free_memory(input, command, com_sep, inputCopy);
		if (inputFile != stdin && feof(inputFile))
			break;
	}
	if (inputFile != stdin)
		fclose(inputFile);
	return (0);
}

/**
 * handle_sigint - Funtion to handle the signal ctrl+c
 * @sig: Represents the signal that triggered the handler
 */

void handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		c_print("\ncisfun($) ");
	}
}
