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
		_putchar(43);
	}
	else if (n == 0)
	{
		return (0);
		_putchar(48);
	}
	else
	{
		return (-1);
		_putchar (45);
	}
}
