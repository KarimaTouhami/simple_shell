#include "shell.h"

/**
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    int i = 0;

    while (1)
    {
        i = 0;
        write(STDOUT_FILENO, "$ ", 2);

        while (read(STDIN_FILENO, &input[i], 1) > 0)
        {
            if (input[i] == '\n' || i == MAX_INPUT_LENGTH - 1)
                break;
            i++;
        }
        input[i] = '\0';

        pid_t pid = fork();

        if (pid == 0)
        {
            int arg_count = 0;
            args[arg_count++] = strtok(input, " \t\n");

            while ((args[arg_count] = strtok(NULL, " \t\n")) != NULL)
            {
                arg_count++;
                if (arg_count >= MAX_ARGS - 1)
                    break;
            }
            args[arg_count] = NULL;

            /* Get the command's full path */
            char *cmd_path = get_path(args[0]);
            if (cmd_path != NULL)
            {
                execve(cmd_path, args, NULL);
                perror("execve");
                free(cmd_path);
                _exit(EXIT_FAILURE);
            }
            else
            {
                char error_message[] = "Command not found: ";
                write(STDERR_FILENO, error_message, strlen(error_message));
                write(STDERR_FILENO, args[0], strlen(args[0]));
                write(STDERR_FILENO, "\n", 1);
                free(cmd_path);
                _exit(EXIT_FAILURE);
            }
        }
        else if (pid > 0)
        {
            wait(NULL);
        }
        else
        {
            perror("fork");
        }
    }

    return (0);
}
