#include "shell.h"
/**
 * make_path - makes a path
 * @path: path to make
 * @cmd: command to add to path
 * Return: path
 */

char *get_path(char *cmd)
{
    char *path = NULL;
    char *path_copy = NULL;
    char *token = NULL;
    char *cmd_path = NULL;
    struct stat st;

    if (stat(cmd, &st) == 0)
        return strdup(cmd);

    if (cmd == NULL)
        return NULL;

    if (cmd[0] == '/')
    {
        if (stat(cmd, &st) == 0)
            return strdup(cmd);
        return NULL;
    }

    path = getenv("PATH");
    path_copy = strdup(path);
    if (path_copy == NULL)
        return NULL;

    token = strtok(path_copy, ":");
    while (token != NULL)
    {
        cmd_path = make_path(token, cmd);
        if (stat(cmd_path, &st) == 0)
        {
            free(path_copy);
            return cmd_path; // Do not free cmd_path here
        }
        free(cmd_path);
        token = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}
