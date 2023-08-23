#include "shell.h"
/**
 * @AUTHOR: Karima Touhami.
 * _strlen - returns the length of a string
 * @k: string to evaluate
 * Return: the length of the string
*/
int _strlen(char *k)
{
	int i = 0;

	if (k == NULL)
		return (0);
	while (k[i] != '\0')
	{
		i++;
	}
	return (i);
}
