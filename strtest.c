#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @str: string to evaluate
 * Return: the length of the string
 */
int _strlen(char *str)
{
    if (str == NULL)
        return (0);

    int length = 0;
    while (*str != '\0')
    {
        length++;
        str++;
    }
    return length;
}
