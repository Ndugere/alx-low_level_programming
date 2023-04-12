#include "main.h"
/**
 * get_endianness - inarudisha endianness
 *
 * Return: 0 for big endian, lakini 1 for little endian
 */
int get_endianness(void)
{
	int y = 1;

	return (*((char *) &y) + '0');
}
