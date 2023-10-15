#include "shell.h"

/**
 * update_env - Funtion to modify and environment variable
 * @name: Name of the environment variable to be modified
 * @value: Value of the environment variable
 * @overwrite: integer flag to know when to overwrite. when set to non-zero
 * it will overwrite and when set to zero it will not overwrite.
 * Return: 0 (success) -1 (not successful)
 */

int update_env(const char *name, const char *value, int overwrite)
{
	int x, name_len, value_len, full_len;
	char *sign, *new_name;

	for (x = 0; environ[x] != NULL; x++)
	{
		sign = _strchr(environ[x], '=');
		if (sign == NULL)
		{
			perror("environ[x]");
			return (-1);
		}
		name_len = sign - environ[x];
		if (_strncmp(name, environ[x], name_len) == 0)
		{
			if (overwrite == 0)
			{
				return (0);
			}
			value_len = _strlen(value);
			full_len = name_len + 1 + value_len + 1;
			new_name = (char *) malloc(full_len);
			if (new_name == NULL)
			{
				perror("Failed to allocate memory");
				return (-1);
			}
			_strcpy(new_name, name);
			_strcat(new_name, "=");
			_strcat(new_name, value);

			environ[x] = new_name;

			return (0);
		}
	}
	return (-1);
}
/**
 * create_env - Funtion to create a new environment variable
 * @name: Name of the environment variable to be modified
 * @value: Value of the environment variable
 * Return: 0 (success) -1 (not successful)
 */

int create_env(const char *name, const char *value)
{
	int x, name_len, value_len, full_len, pos = 0;
	char *new_name;
	char **new_environ;

	name_len = _strlen(name);
	value_len = _strlen(value);
	full_len = name_len + 1 + value_len + 1;
	new_name = malloc(sizeof(char) * full_len);
	if (new_name == NULL)
	{
		perror("Failed to allocate memory");
		return (-1);
	}
	_strcpy(new_name, name);
	_strcat(new_name, "=");
	_strcat(new_name, value);
	for (x = 0; environ[x] != NULL; x++)
	{
		pos++;
	}
	new_environ = malloc(sizeof(char *) * (pos + 2));
	if (new_environ == NULL)
	{
		perror("Failed to allocate memory");
		free(new_name);
		return (-1);
	}
	for (x = 0; x < pos; x++)
	{
		new_environ[x] = environ[x];
	}
	new_environ[pos] = new_name;
	new_environ[pos + 1] = NULL;
	environ = new_environ;

	return (0);
}

/**
 * _setenv - Funtion to set an environment variable
 * @name: Name of the environment variable
 * @value: Value of the environment variable
 * @overwrite: integer flag to know when to overwrite. when set to non-zero
 * it will overwrite and when set to zero it will not overwrite.
 * Return: 0 (success) -1 (not successful)
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	if (name == NULL || value == NULL)
	{
		perror("Invalid arguments");
		return (-1);
	}
	if (update_env(name, value, overwrite) == 0)
	{
		return (0);
	}
	if (create_env(name, value) == 0)
	{
		return (0);
	}

	return (-1);
}

/**
 * _unsetenv - Funtion to delete an environment variable
 * @name: Name of the environment variable
 * Return: 0 (success) -1 (not successful)
 */

int _unsetenv(const char *name)
{
	int x, y;
	size_t len;

	if (name == NULL || *name == '\0' || _strchr(name, '=') != NULL)
	{
		return (-1);
	}
	len = _strlen(name);

	for (x = 0; environ[x] != NULL; x++)
	{
		if (_strncmp(environ[x], name, len) == 0 && environ[x][len] == '=')
		{
			if (environ[x] != NULL)
			{
				free(environ[x]);
			}
			for (y = x; environ[y] != NULL; y++)
			{
				environ[y] = environ[y + 1];
			}
			--x;
		}
	}
	return (0);
}
