#include "main.h"

/**
 * @AUTORS: Karima Touhami.
 * main - Entry point of the simple shell.
 * Return: Always 0.
 */
*/

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];
    char *token;

    while (1)
    {
        printf("SimpleShell> ");
        fgets(input, sizeof(input), stdin);

        /* Remove the newline character from input */
        input[strcspn(input, "\n")] = '\0';

        /* Tokenize the input */
        token = strtok(input, " ");
        int arg_count = 0;

        while (token != NULL)
        {
            args[arg_count] = token;
            arg_count++;
            token = strtok(NULL, " ");
        }

        if (arg_count > 0)
        {
            args[arg_count] = NULL; /* Set the last element to NULL as required by execvp */
            if (strcmp(args[0], "exit") == 0)
            {
                exit(EXIT_SUCCESS);
            }
            execute_command(args[0], args);
        }
    }

    return (0);
}
