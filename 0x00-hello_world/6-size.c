#include <stdio.h>
/**
 * main - a C program that prints the size
 * Return: 0
 */
int main(void)
{
	char a;
	int b;
	long int c;
	long long int d;
	float f;
	{
	printf("Size of a char: %i byte(s)\n", sizeof(a));
	printf("Size of an  int: %i byte(s)\n", sizeof(b));
	printf("Size of a long int: %i byte(s)\n", sizeof(c));
	printf("Size of a long long int: %i byte(s)\n", sizeof(d));
	printf("Size of a float: %i byte(s)\n", sizeof(f));
	return (0);
	}
}
