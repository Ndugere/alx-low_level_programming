#include <stdio.h>
/**
 * main - base kumi na sita
 * Return: 0
 */
int main(void)
{
	int a;
	char l;

	for (a = 0; a <= 9; a++)
		putchar((a % 10) + '0');
	for (l = 'a'; l <= 'f'; l++)
		putchar(l);
	putchar('\n');

	return (0);
}
