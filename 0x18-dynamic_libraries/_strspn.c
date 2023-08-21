#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to search
 * @accept: The characters to search for
 *
 * Return: Number of bytes in the initial segment of s which consist
 *         only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
    unsigned int count = 0;
    int found;

    while (*s)
    {
        found = 0;
        for (int i = 0; accept[i]; i++)
        {
            if (*s == accept[i])
            {
                found = 1;
                count++;
                break;
            }
        }
        if (!found)
            break;
        s++;
    }
    return count;
}
