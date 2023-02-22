#include "main.h"
/**
 * print_sign - checking sings
 * Return: sio zero 1 when positive na 0 when neg
 * @n: value inaingia
 */
int print_sign(int n)
{
	if (n > 0)
	{
		return (1);
		_putchar('+');
	}
	else if (n == 0)
	{
		return (0);
		_putchar('0');
	}
	else
	{
		return (-1);
		_putchar ('-');
	}
}
