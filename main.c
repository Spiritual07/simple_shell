#include "shell.h"

/**
 * handle_builtin_commands - Function to handle builtin commands
 * @B: struct handle_builtin variable
 */

void handle_builtin_commands(handle_builtin *B)
{
	size_t x;

	for (x = 0; B->com_sep[x] != NULL; x++)
	{
		B->command = tokenize(B->com_sep[x], TOK_DELIM, false);
		if (B->command == NULL || B->command[0] == NULL)
		{
			free_com(B->command);
			continue;
		}
		if (_strcmp(B->command[0], "env") == 0)
		{
			handle_env_command(B->env);
			free_com(B->command);
			continue;
		}
		if (_strcmp(B->command[0], "cd") == 0)
		{
			cd(B->command[1]);
			free_com(B->command);
			continue;
		}
		if (_strcmp(B->command[0], "exit") == 0)
		{
			*B->status = get_exit_stat(B->command, *B->status);
			handle_exit_com(B->input, B->command, B->com_sep, B->inputCopy,
							B->inputFile, *B->status);
		}
		if (_strcmp(B->command[0], "echo") == 0)
		{
			echo_arg(B->command, *B->status);
			free_com(B->command);
			continue;
		}
		*B->status = executeCommand(B->command, B->argc, B->argv);
		free_com(B->command);
	}
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
	char **command = NULL, **com_sep;
	char *input, *inputCopy;
	int status = 0;
	size_t len = 0;
	handle_builtin builtin;

	signal(SIGINT, handle_sigint);
	while (argc)
	{
		if (isatty(STDIN_FILENO))
			c_print("cisfun$ ");
		input = processInput(&len, inputFile);
		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}
		inputCopy = _strdup(input);
		com_sep = tokenize(inputCopy, ";||&&", true);
		builtin.input = input;
		builtin.command = command;
		builtin.com_sep = com_sep;
		builtin.inputCopy = inputCopy;
		builtin.inputFile = inputFile;
		builtin.status = &status;
		builtin.env = env;
		builtin.argc = argc;
		builtin.argv = argv;
		handle_builtin_commands(&builtin);
		free_memory(input, command, com_sep, inputCopy);
		if (inputFile != stdin && feof(inputFile))
			break;
	}
	if (inputFile != stdin)
		fclose(inputFile);
	return (0);
}

