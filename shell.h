#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 64
#define MAX_ARGS 16

void execute_command(char *command, char **args);

#endif /* SHELL_H */
