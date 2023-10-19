#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

#define MAX_INPUT_LEN 1024

#define UNUSED(x) (void)(x)
#define MAX_INPUT_LENGTH 1024
extern char **environ;

/*Strings*/
char *_strpbrk(char *s, const char *accept);
char *_strchr(const char *s, char c);
char *_strtok(char *str, const char *delimiters);
int _strcmp(char *s1, char *s2);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *s);

/* shell functions */
int main(int argc, char *argv[]);
void print_prompt(void);
void execute_command(char *input, char *argv0);
char *read_input(void);
void handle_exit(char *input);
void print_env(char *input);
char **split_path(void);
void free_path(char **path);
char *get_path(char *in);
int split_args(char *command, char **args);
void execute_child(char **args, char *cmd, char *argv0);


#endif
