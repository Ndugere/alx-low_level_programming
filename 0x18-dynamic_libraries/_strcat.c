#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination buffer
 * @src: The source string
 *
 * Return: Pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
