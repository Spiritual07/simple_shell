#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>
#include <signal.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_PATH 1024
#define INIT_BUFSIZE 32
#define BUFFERSIZE 1024
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct handle_builtin - structure for handling built-in commands it contains
 * various fields for storing information about the command being executed
 * @command: A pointer to an array of strings, where each string is a
 * token from a command line input.
 * @com_sep: A pointer to an array of strings, where each string is a
 * separate command to be executed
 * @input: A pointer to a string that contains the raw input from the user.
 * @inputCopy: copy of input
 * @inputFile: A pointer to a file from which input is being read.
 * @status: A pointer to an integer that stores the exit status of
 * the last command executed.
 * @env: A pointer to an array of strings where each string is
 * an environment variable
 * @argc: The count of command line arguments passed to the program.
 * @argv: A pointer to an array of strings, where each string
 * is a command line argument.
 */

typedef struct handle_builtin
{
		char **command;
		char **com_sep;
		char *input;
		char *inputCopy;
		FILE *inputFile;
		int *status;
		char **env;
		int argc;
		char **argv;
} handle_builtin;

void handle_builtin_commands(handle_builtin *builtin);



void c_print(char *str);
void _print(char *str);
int _putchar(char c);
void p_error(char *input, int count, char *av[]);
void print_error(char *path);


int _strlen(const char *str);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strcspn(char *str, char *reject);
char *_strdup(char *str);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(const char *s, char c);
int _atoi(char *str);
char *_itoa(unsigned int n);
void _readLine(char **lineptr, size_t *buf_size, char *buffer, size_t len);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, size_t oldSize, size_t newSize);
char *c_strtok(char *str, const char *delim);
char *_strpbrk(char *str, const char *accept);
unsigned int _strspn(char *str, const char *accept);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);

FILE *open_input_file(int argc, char *argv[]);
void handle_env_command(char **env);
void handle_exit_com(char *input, char **command, char **com_sep,
				char *inputCopy, FILE *inputFile, int status);
int executeCommand(char **command, int argc, char *argv[]);
int execute_com(char **command, int argc, char *f_path, char *argv[]);
int handle_abs_path(char **command, char *f_path, size_t f_path_size);
int search_path_dirs(char **command, char *f_path, size_t f_path_size);
int check_cwd(char **command, char *f_path, size_t f_path_size);
int cd(char *pth);
char *_getenv(const char *name);

char *cd_home(void);
void cd_to_dir(char *path, char *prev_dir);
int cd_to_prev_dir(void);
void update_pwd(void);
int cd(char *path);
void handle_comments(char *str);

char *processInput(size_t *len, FILE *inputFile);
char **tokenize(char *input, char *delim, bool splitCommands);
int echo_com(char **command);
int echo_arg(char **command, int lastComStat);
int print_num(int n);
void print_ui(unsigned int n);
int get_exit_stat(char **command, int last_com_stat);

void handle_sigint(int sig);
void free_memory(char *input, char **command, char **com_sep, char *inputCopy);
void free_com(char **command);

int update_env(const char *name, const char *value, int overwrite);
int create_env(const char *name, const char *value);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);

#endif
