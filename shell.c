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
			/* Child process */
			args[0] = input;
			args[1] = NULL;
			execve(input, args, NULL);

			/* If execve fails, print an error message and exit */
			char error_msg[] = "Error\n";
			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
			_exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			wait(NULL);
		}
		else
		{
			char error_msg[] = "fork\n";
			write(STDERR_FILENO, error_msg, sizeof(error_msg) - 1);
		}
	}

	return 0;
}
