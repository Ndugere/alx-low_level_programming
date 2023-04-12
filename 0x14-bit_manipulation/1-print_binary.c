#include "main.h"
#include <unistd.h>
#include <limits.h>
/**
 * print_binary - hii nayo inaprint an unsigned int in binary
 *
 * @n:
 *
 * Return: rudisha void
 */
void print_binary(unsigned long int n)
{
	unsigned long int pribit = 1ul << 63;
	char c = '0';

	while (!(pribit & n) && pribit != 0)
		pribit = pribit >> 1;

	if (pribit == 0)
		write(1, &c, 1);

	while (pribit)
	{
		if (pribit & n)
			c = '1';
		else
			c = '0';
		write(1, &c, 1);
		pribit = pribit >> 1;
	}
}

