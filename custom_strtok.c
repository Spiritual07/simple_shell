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
	char *token = NULL;

	if (str != NULL)
		f_input = str;
	if (f_input == NULL)
		return (NULL);
	token = f_input;

	for (; *f_input != '\0'; f_input++)
	{
		if (_strchr(delim, *f_input) != NULL)
		{
			*f_input = '\0';
			f_input++;
			return (token);
		}
	}
	return (token);
}
