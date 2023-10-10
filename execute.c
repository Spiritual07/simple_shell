#include "shell.h"

/**
 * check_cwd - function that search current directory for executable file
 * @command: array of strings representing a command
 * @f_path: a character buffer to store the full path of the executable.
 * @f_path_size: size of the fullpath
 * Return: number of executable command found
 */

int check_cwd(char **command, char *f_path, size_t f_path_size)
{
	int command_found = 0;
	int access_result = -1;

	/* Check the current working directory first */
	if (getcwd(f_path, f_path_size) != NULL)
	{
		_strncat(f_path, "/", f_path_size - _strlen(f_path) - 1);
		_strncat(f_path, command[0], f_path_size - _strlen(f_path) - 1);

		/* If the file exists and is executable, run it */
		access_result = access(f_path, X_OK);
		if (access_result == 0)
		{
			command_found = 1;
		}
	}

	return (command_found);
}

/**
 * search_path_dirs - Function to search the PATH directories
 * @command: array of strings representing a command
 * @f_path: a character buffer to store the full path of the executable.
 * @f_path_size: size of the fullpath
 * Return: number of executable command found
 */

int search_path_dirs(char **command, char *f_path, size_t f_path_size)
{
	int command_found = 0;
	char *path, *path_copy, *dir;
	int access_result = -1;

	path = getenv("PATH");
	path_copy = _strdup(path); /* Create a copy of the PATH string */
	if (path_copy == NULL)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		_strncpy(f_path, dir, f_path_size - 1);
		f_path[f_path_size - 1] = '\0';
		_strncat(f_path, "/", f_path_size - _strlen(f_path) - 1);
		_strncat(f_path, command[0], f_path_size - _strlen(f_path) - 1);

		/* If the file exists and is executable, run it */
		access_result = access(f_path, X_OK);
		if (access_result == 0)
		{
			command_found = 1;
			break;
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy); /* Free the copy of the PATH string */

	return (command_found);
}

/**
 * handle_abs_path - Function to handle command if it's an absolute path
 * @command: array of strings representing a command
 * @f_path: a character buffer to store the full path of the executable.
 * @f_path_size: size of the fullpath
 * Return: number of executable command found
 */

int handle_abs_path(char **command, char *f_path, size_t f_path_size)
{
	int command_found = 0;
	int access_result = -1;

	/* If the command is an absolute path, copy it to fullpath */
	_strncpy(f_path, command[0], f_path_size - 1);
	f_path[f_path_size - 1] = '\0';
	access_result = access(f_path, X_OK);
	if (access_result == 0)
	{
		command_found = 1;
	}

	return (command_found);
}

/**
 * execute_com - Function to execute the command
 * @command: array of strings representing a command
 * @environ: An array of strings representing the environment variables.
 * @f_path: a character buffer to store the full path of the executable.
 */

void execute_com(char **command, char **environ, char *f_path, char *argv[])
{
	int stat_loc;
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(f_path, command, environ) == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(child_pid, &stat_loc, WUNTRACED) == -1)
		{
			perror("waitpid failed");
			exit(EXIT_FAILURE);
		}
	}
}

