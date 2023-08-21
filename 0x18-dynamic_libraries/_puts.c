#include "main.h"

/**
 * _puts - Prints a string followed by a new line
 * @s: The string to be printed
 */
void _puts(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        _putchar(s[i]);
        i++;
    }
    _putchar('\n');
}
