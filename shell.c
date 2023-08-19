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
            /* Child process code */
        }
        else if (pid > 0)
        {
            /* Parent process code */
        }
        else
        {
            perror("fork");
        }
    }

    return (0);
}
