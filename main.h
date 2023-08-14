#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_LENGTH 64
#define MAX_ARGS 16

/* strtest.c */
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);

#endif
