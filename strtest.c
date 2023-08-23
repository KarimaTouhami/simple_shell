#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @s: String to evaluate.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
    if (s == NULL)
        return (0);

    int length = 0;
    char *current = s;

    while (*current != '\0')
    {
        length++;
        current++;
    }

    return (length);
}
