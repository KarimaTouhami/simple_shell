#include "shell.h"

/**
 * @AUTHORS: Karima Touhami.
 * main - Entry point of the shell program.
 *
 * Return: Always 0.
 */
int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    char *token;

    while (1)
    {
        write(STDOUT_FILENO, ":) ", 3);
        ssize_t n_read = read(STDIN_FILENO, input, sizeof(input));

        if (n_read == 0)
        {
            write(STDOUT_FILENO, "\n", 1);
            break; // End of file (Ctrl+D)
        }

        // Remove the newline character from input
        input[n_read - 1] = '\0';

        int argCount = 0;

        // Tokenize the input into arguments
        token = strtok(input, " ");
        while (token != NULL && argCount < MAX_ARGS - 1)
        {
            args[argCount] = token;
            argCount++;
            token = strtok(NULL, " ");
        }
        args[argCount] = NULL;

        if (argCount == 0)
            continue; // Empty command, prompt again

        if (strcmp(args[0], "exit") == 0)
            exit(0);

        execute_command(args[0], args);
    }

    return 0;
}

/**
 * execute_command - Execute a command with specified arguments.
 * @command: The command to execute.
 * @args: An array of arguments for the command.
 */
void execute_command(char *command, char **args)
{
    pid_t pid = fork();

    if (pid == 0)
    {
        // Child process
        execvp(command, args);
        perror("execvp");
        _exit(1);
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
