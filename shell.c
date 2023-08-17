#include "shell.h"

/**
 * @AUTHOR: Karima Touhami.
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char c;
    char *args[2];
    int i = 0;

    while (1)
    {
        i = 0;
        write(STDOUT_FILENO, "$ ", 2);

        while (read(STDIN_FILENO, &c, 1) > 0)
        {
            if (c == '\n' || i == MAX_INPUT_LENGTH - 1)
                break;
            input[i++] = c;
        }
        input[i] = '\0';

        pid_t pid = fork();

        if (pid == 0)
        {
            args[0] = input;
            args[1] = NULL;
            execve(input, args, NULL);

            perror("execve");
            _exit(EXIT_FAILURE);
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

    return 0;
}
