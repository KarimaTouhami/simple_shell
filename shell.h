#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64
#define PATH_MAX_LENGTH 1024

void execute_command(char *command, char **args);
void print_environment(void);

#endif /* SHELL_H */
