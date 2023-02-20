#include <stdio.h>
/**
 * main - kazi ngumu
 * Return: 0
 */
int main(void)
{
	int i = 0;

	while (i < 5)
	{
		putchar(i + '0');
			i++;
		putchar(',');
		putchar(' ');
	}
	putchar('5');

	return (0);
}
