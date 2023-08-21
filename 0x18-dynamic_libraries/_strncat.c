#include "main.h"

/**
 * _strncat - Concatenates n bytes of a string to another string
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of bytes to concatenate
 *
 * Return: Pointer to the destination buffer
 */
char *_strncat(char *dest, char *src, int n)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
