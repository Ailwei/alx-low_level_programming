#include "main.h"
/**
 * print_number - Prints an integer.
 * @n: The integer to be printed.
 *
 * This function prints the given integer using only the _putchar function.
 * It handles negative numbers and does not rely on long, arrays, pointers,
 * or hard-coded special values.
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
	{
		n1 = n;
	}
	if (n1 / 10)
	{
		print_number(n1 / 10);
	}
	_putchar((n1 % 10) + '0');
}
