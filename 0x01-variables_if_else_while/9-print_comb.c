#include <stdio.h>
/**
 * main - kazi ngumu
 * Return: 0
 */
int main(void)
{
	int i = 0;

	while (i < 9)
	{
		putchar(i + '0');
			i++;
		putchar(',');
		putchar(' ');
	}
	putchar('9');

	return (0);
}
