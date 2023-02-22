#include "main.h"
/**
 * _isalpha - checking for aphabet
 * Return: rudisha moja if alphabet rudisha zero if not
 * @c: the character
 */
int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
