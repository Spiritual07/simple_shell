#include "shell.h"

/**
 * _readLine - Function that update lineptr and buf_size with the
 * appropriate values based on the length of the line read.
 * @lineptr: A pointer to a pointer to a character, which is
 * intended to hold the result of the line read.
 * @buf_size: A pointer to a size_t integer, which represents
 * the size of the buffer.
 * @buffer: A character array that contains the characters
 * read from the input stream.
 * @len: An integer representing the length of the line read.
 */

void _readLine(char **lineptr, size_t *buf_size, char *buffer, size_t len)
{
	if (*lineptr == NULL)
	{
		*buf_size = len > INIT_BUFSIZE ? len : INIT_BUFSIZE;
		*lineptr = buffer;
	}
	else if (*buf_size < len)
	{
		*buf_size = len > INIT_BUFSIZE ? len : INIT_BUFSIZE;
		*lineptr = realloc(*lineptr, *buf_size * sizeof(char));
		if (*lineptr == NULL)
		{
			perror("Unable to allocate buffer");
			exit(EXIT_FAILURE);
		}
		_strncpy(*lineptr, buffer, *buf_size);
		free(buffer);
	}
	else
	{
		_strncpy(*lineptr, buffer, *buf_size);
		free(buffer);
	}
}

/**
 * _getline - Function that read lines of text from a file stream.
 * @lineptr: A pointer to a pointer to a character, where the result
 * of the line read will be stored
 * @buf_size: A pointer to a size_t integer, which
 * represents the size of the buffer.
 * @stream: A file stream from which to read the text.
 * Return: The number of characters read.
 */

ssize_t _getline(char **lineptr, size_t *buf_size, FILE *stream)
{
	size_t len = 0, new_bufsize = INIT_BUFSIZE;
	int c;
	char *buffer;

	buffer = malloc(new_bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	while ((c = fgetc(stream)) != EOF)
	{
		if (len >= new_bufsize - 1) /* Leave space for '\0' */
		{
			new_bufsize = new_bufsize + new_bufsize;
			buffer = realloc(buffer, new_bufsize * sizeof(char));
			if (buffer == NULL)
			{
				perror("Unable to reallocate buffer");
				exit(EXIT_FAILURE);
			}
		}
		buffer[len++] = (char)c;
		if (c == '\n')
			break;
	}
	if (c == EOF && len == 0) /* Nothing was read */
	{
		free(buffer);
		return (-1);
	}
	buffer[len] = '\0';
	_readLine(lineptr, buf_size, buffer, len);
	return (len);
}
