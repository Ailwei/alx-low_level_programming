#include "main.h"
/**
 * _abs - Computes the absolute value of an integer.
 *
 * @param n: num The input integer.
 * @return The absolute value of the input integer.
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
