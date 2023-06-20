#include "main.h"
/**
 * _abs - Computer the absolute value of an integer
 * @c: The number to be computed.
 * Return:Absolute value of number or zero
 */

int _abs(int n)
{
	if (n < 0)
	{
		int abs_val;

		abs_val = n * -1;

		return (abs_val);
	}
	return (n);
}
