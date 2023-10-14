#include "shell.h"

/**
  *c_strtok - function breaks a string into a sequence of zero or more tokens
  *@str: the string to tokenize
  *@delim: this argument delimit tokens
  *Return: a pointer to the next token or NULL
  */

char *c_strtok(char *str, const char *delim)
{
	static char *f_input;
	char *token_start = NULL;
	char *delim_pos = NULL;

	if (str != NULL)
		f_input = str;
	if (f_input == NULL)
		return (NULL);

	/* Skip any leading delimiters */
	f_input += _strspn(f_input, delim);
	if (*f_input == '\0') /* Check if we have reached the end of the string */
	{
		f_input = NULL;
		return (NULL);
	}

	token_start = f_input;
	delim_pos = _strpbrk(f_input, delim);

	if (delim_pos != NULL)
	{
		*delim_pos = '\0';
		f_input = delim_pos + 1;
	}
	else
	{
		f_input = (NULL);
	}

	return (token_start);
}

/**
 * echo - Excute echo command
 * @command: Input command
 * Return: 0 (Succes)
 */
int echo(char **command)
{
	pid_t pid;
	int stat_loc;

	pid = fork();
	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve("/bin/echo", command, environ) == -1)
		{
			perror(command[0]);
			return (-1);
		}
	}
	else
	{
		waitpid(pid, &stat_loc, WUNTRACED);
		while (!WIFEXITED(stat_loc) && !WIFSIGNALED(stat_loc))
		{
			waitpid(pid, &stat_loc, WUNTRACED);
		}
	}
	return (0);
}

/**
 * echo_arg - Excute cases where arguments are passed to echo
 * @lastComStat:Status of the last command executed
 * @command: Input command
 * Return: 0 (success)
 */
int echo_arg(char **command, int lastComStat)
{
	char *path = NULL;
	unsigned int  pid = getppid();

	if (_strcmp(command[1], "$?") == 0)
	{
		print_num(lastComStat);
		c_print("\n");
	}
	else if (_strcmp(command[1], "$$") == 0)
	{
		print_num(pid);
		c_print("\n");
	}
	else if (_strcmp(command[1], "$PATH") == 0)
	{
		path = getenv("PATH");
		c_print(path);
		c_print("\n");
	}
	else
		echo(command);

	return (0);
}
