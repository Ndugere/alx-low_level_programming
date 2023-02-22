#include "main.h"
/**
 * _abs - kuona absolute values
 * Return: inarudisha c ama abs_val
 * @c: ndio tunacheck
 */
int _abs(int c)
{
	if (c < 0)
	{
		int abs_val;

		abs_val = c * -1;
		return (abs_val);
	}
	else
	{
		return (c);
	}
}
