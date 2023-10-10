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
		write(STDOUT_FILENO, env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}

/**
 * handle_exit_command - Function to handle exit command
 * @input: Pointer that will be used to store the user input.
 * @command: An array of strings representing the command and its arguments.
 * @inputFile:  A pointer to a FILE object, representing the input
 * file from which the function will read lines of text.
 */

void handle_exit_command(char *input, char **command, FILE *inputFile)
{
	free(input);
	free(command);
	if (inputFile != stdin)
	{
		fclose(inputFile);
	}
	exit(EXIT_SUCCESS);
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
	char **command;
	char *input = NULL;
	size_t len = 0;

	while (argc == 1)
	{
		if (isatty(STDIN_FILENO))
			c_print("$ ");
		input = processInput(&len, inputFile);
		command = tokenize(input);
		if (command == NULL)
		{
			free(input);
			free(command);
			continue;
		}
		if (_strcmp(command[0], "env") == 0)
		{
			handle_env_command(env);
			continue;
		}
		if (_strcmp(command[0], "exit") == 0)
			handle_exit_command(input, command, inputFile);
		executeCommand(command, env);
		free(input);
		free(command);
		input = NULL;
		command = NULL;
		if (inputFile != stdin && feof(inputFile))
			break;
	}
	if (inputFile != stdin)
		fclose(inputFile);
return (0);
}
