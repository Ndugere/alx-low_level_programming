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
		_putchar(43);
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar (45);
		return (-1);
	}
}
