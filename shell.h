#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stddef.h>

#define MAX_PATH 1024

void c_print(char *str);

/* My custom string.h functions */
int _strlen(char *str);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strcspn(char *str, char *reject);
char *_strdup(char *str);


FILE *open_input_file(int argc, char *argv[]);
void handle_env_command(char **env);
void handle_exit_command(char *input, char **command, FILE *inputFile);
void executeCommand(char **command, char **environ, char *argv[]);
void execute_com(char **command, char **environ, char *f_path, char *argv[]);
int handle_abs_path(char **command, char *f_path, size_t f_path_size);
int search_path_dirs(char **command, char *f_path, size_t f_path_size);
int check_cwd(char **command, char *f_path, size_t f_path_size);


char *processInput(size_t *len, FILE *inputFile);
char **tokenize(char *input);

#endif
