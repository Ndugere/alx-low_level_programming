#include <stdio.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int x = 0;
	int sum = 0;
	int y = 1;
	int n;

	for (n = 0; n <= 50; n++)
	{
		sum = x + y;
		if (sum < 1)
		{
			sum = sum * -1;
		}
		printf("%d, ", sum);
		x = y;
		y = sum;
	}
	return (0);
}
