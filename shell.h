#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT 1024
#define MAX_ARGS 10
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include <signal.h>
#include <stdarg.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>

void prompt(void);
void read_input(char *input);
void parse_input(char *, char **);
void execute_command(char *command, char **args);
void sigint_handler(int sig);
void sigquit_handler(int sig);
void _puts(char *str);
int _strncmp(const char *s1, const char *s2, size_t n);
int _strcmp(char *s1, char *s2);
int _strlen(char *p);
char *find_path(void);
char *_combine_path(const char *s1, const char *s2);
char **split(char *path, char *del);
int run_cmd(char *line);
char *_strdup(char *str);
int cmd_helper(char **pathsp, char **splitted);
void free_2d_array(char **ptr);
int exit_status(int action, int new_status);
void my_exit(char *input, char *command);
void env(void);
int _input(char *str);

#define READ_SIZE 1024
#define BUFSIZE 1024

/* handle_path.c */
char *get_path(char *cmd);
char *make_path(char *path, char *cmd);

#endif /* SHELL_H */

