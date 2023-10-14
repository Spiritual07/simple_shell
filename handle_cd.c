#include "shell.h"


/**
 * cd_home - Change to home directory
 * Return: Home directory
 */

char *cd_home(void)
{
	char *home;

	home = getenv("HOME");
	if (home == NULL)
	{
		perror("shell");
		exit(1);
	}
	return (home);
}

/**
 * cd_to_dir - A function to change to the specified directory
 * @path: Path to the directory to change to
 * @prev_dir: Previous directory
 */

void cd_to_dir(char *path, char *prev_dir)
{
	char cwd[BUFFERSIZE];

	if (path[0] != '/')
	{
		getcwd(cwd, BUFFERSIZE);
		_strcat(cwd, "/");
		_strcat(cwd, path);
		if (chdir(cwd) == -1)
		{
			perror("shell");
		}
	}
	getcwd(prev_dir, BUFFERSIZE);
}

/**
 * cd_to_prev_dir - A function to handle changing to the previous directory
 * Return: 0 (success);
 */

int cd_to_prev_dir(void)
{
	char cwd[BUFFERSIZE];

	if (chdir(getenv("OLDPWD")) == -1)
	{
		perror("cd");
		return (-1);
	}
	getcwd(cwd, sizeof(cwd));
	setenv("OLDPWD", getenv("PWD"), 1);
	setenv("PWD", cwd, 1);

	c_print(cwd);
	c_print("\n");

	return (0);
}

/**
 * update_pwd - A function to update the environment variable "PWD"
 */

void update_pwd(void)
{
	char newcwd[BUFFERSIZE];

	if (getcwd(newcwd, BUFFERSIZE) != NULL)
	{
		setenv("PWD", newcwd, 1);
	}
	else
	{
		perror("Shell");
	}
}

/**
 * cd - Function to change directory to specified path
 * @path: path specified
 * Return: 0 (success);
 */

int cd(char *path)
{
	static char prev_dir[BUFFERSIZE] = "";

	getcwd(prev_dir, BUFFERSIZE);

	if (path == NULL)
	{
		chdir(cd_home());
	}
	else if (_strcmp(path, "-") == 0)
	{
		cd_to_prev_dir();
	}
	else
	{
		cd_to_dir(path, prev_dir);
	}
	update_pwd();

	return (0);
}
