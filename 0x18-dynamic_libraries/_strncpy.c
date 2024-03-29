#include "main.h"

/**
 * _strncpy - Copies n bytes of a string to another
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of bytes to copy
 *
 * Return: Pointer to the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for ( ; i < n; i++)
        dest[i] = '\0';

    return dest;
}
