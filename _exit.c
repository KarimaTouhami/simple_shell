#include "shell.h"
/**
 * my_exit - Frees memory and exits the program.
 * @input: Pointer to the input string.
 * @command: Pointer to the command string.
 * This function frees the memory allocated for the
 * input and command strings
 * and then exits the program with the status
 * returned by the status_exit() function.
 */

void my_exit(char *input, char *command)
{
	free(input);
	free(command);
	exit(exit_status(0, 0));
}
/**
 * exit_status - Manages the exit status for a given action and new status
 * @action: The action to perform (1 for set, 0 for get)
 * @new_status: The new status to set
 * Return: The current exit status if action is 0,
 * or the new status if action is 1
 */
int exit_status(int action, int new_status)
{
	static int status;

	if (action == 1)
		status = new_status;
	return (status);
}
