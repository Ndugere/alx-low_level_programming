#include "main.h"
/**
 * flip_bits - flip yetu
 * @n: inputama mwanzo
 * @m: bitsss
 * Return: 0
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int hesabu = 0;

	while (n != 0 || m != 0)
	{
		if ((n & 1) != (m & 1))
			hesabu++;
		m = m >> 1;
		n = n >> 1;
	}

	return (hesabu);

}
