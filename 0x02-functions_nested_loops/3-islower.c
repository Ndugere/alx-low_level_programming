#include "main.h"
/**
 * _islower - this checks if c is lower case or upper case
 * Return: 1 if lower
 * @c: the character to be checked
 * returns zero if not
 */
int _islower(int c)
{
	char c;

	if (c >= 97 && c <= 122)
	{
		return (1);
		else
		{
			return (0);
		}
	}
}
