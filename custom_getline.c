#include "shell.h"

/**
  *read_stdin - this function reads from the standard input
  *
  *Return: this returns the input in the buffer
  */

char read_stdin(void)
{
	static int buf_index, buf_size;
	static char buffer[BUF_SIZE];

	if (buf_size <= buf_index)
	{
		buf_size = read(STDIN_FILENO, buffer, BUF_SIZE);
		buf_index = 0;
		if (buf_size <= 0)
			return ('\0');
	}
	return (buffer[buf_index++]);
}

/**
  *allocate_line - this function allocates memory for a new line
  *@line: this hold whatever the allocated memory for new line
  *@_size: this is size of the line
  *@rangeof_line: this is the size of memory it allocates to new line
  *Return: this returns the line after copy from the new line
  */

char *allocate_line(char *line, int *_size, int *rangeof_line)
{
	char *new_line = NULL;
	int i;

	if (*rangeof_line <= (*_size + 1))
	{
		*rangeof_line = (*rangeof_line + 1) * 2;
		new_line = malloc(*rangeof_line);
		if (new_line == NULL)
		{
			perror("unsuccessful allocation");
			exit(1);
		}
		if (*_size > 0)
		{
			for (i = 0; i < *_size; i++)
				new_line[i] = line[i];
			free(line);
		}
		line = new_line;
	}
	return (line);
}

/**
  *c_getline - this function appends characters to the line
  *
  *Return: returns line after appending
  */

char *c_getline()
{
	char *line = NULL;
	int _size = 0;
	int rangeof_line = 0;
	char temp;

	for (;;)
	{
		temp = read_stdin();
		if (temp == '\0' && _size == 0)
			return (NULL);
		else if (temp == '\0')
			break;

		line = allocate_line(line, &_size, &rangeof_line);
		line[_size++] = temp;
		if (temp == '\n')
			break;
	}
	if (_size)
		line[_size] = '\0';
	return (line);
}
