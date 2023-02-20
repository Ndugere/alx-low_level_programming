#include <stdio.h>
/**
 * main - kazi ngumu
 * Return: 0
 */
int main(void)
{
	int i = 0;

	while (i <= 9)
	{
		putchar(i + '0');
		{
			if (i == 9)
				break;
		}
		i++;
		putchar(',');
		putchar(' ');
	}
	putchar('\n');

	return (0);
}
