#include "shell.h"
/**
 * _strlen - Returns the length of a string.
 * @str: The input string.
 * Return: The length of the string.
 */
int _strlen(char *str)
{
    if (str == NULL)
        return 0;

    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
