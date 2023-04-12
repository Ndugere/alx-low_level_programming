#include "main.h"
/**
 * set_bit - anzisha ama Entry Point
 * @n: input/ kuweka
 * @index: indexxx
 * Return: 0
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = *n | 1ul << index;
	return (1);
}
