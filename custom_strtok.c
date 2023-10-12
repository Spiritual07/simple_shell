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
