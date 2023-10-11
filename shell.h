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

#define MAX_PATH 1024
#define INIT_BUFSIZE 32

extern char **environ;


void c_print(char *str);
void errorMsg(char *input, int count, char *av[]);


/* My custom string.h functions */
int _strlen(char *str);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strcspn(char *str, char *reject);
char *_strdup(char *str);
char *_memcpy(char *dest, char *src, unsigned int n);

int _atoi(char *str);
char *_itoa(unsigned int n);
void _readLine(char **lineptr, size_t *buf_size, char *buffer, size_t len);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int new_size);

FILE *open_input_file(int argc, char *argv[]);
void handle_env_command(char **env);
void handle_exit_com(char *input, char **command, FILE *inputFile, int status);
void executeCommand(char **command, int argc, char *argv[]);
void execute_com(char **command, int argc, char *f_path, char *argv[]);
int handle_abs_path(char **command, char *f_path, size_t f_path_size);
int search_path_dirs(char **command, char *f_path, size_t f_path_size);
int check_cwd(char **command, char *f_path, size_t f_path_size);

char *processInput(size_t *len, FILE *inputFile);
char **tokenize(char *input);

#endif
