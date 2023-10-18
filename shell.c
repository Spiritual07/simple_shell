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

/**
 * get_exit_stat - Funtion to get exit status
 * @command: array of command passed
 * @last_com_stat: Last command status
 * Return: last command status
 */

int get_exit_stat(char **command, int last_com_stat)
{
	int x = 1, status;
	char *msg;

	if (command[1])
	{
		status = _atoi(command[1]);
		if (status < 0)
		{
			msg = _itoa(x);
			_print("./hsh: ");
			_print(msg);
			_print(": ");
			_print(command[0]);
			_print(": ");
			_print("Illegal number: ");
			_print(command[1]);
			_print("\n");
			free(msg);
			return (2);
		}
		else if (status > 255)
		{
			last_com_stat = status % 256;
		}
		else
		{
			return (status);
		}
	}
	return (last_com_stat);
}
