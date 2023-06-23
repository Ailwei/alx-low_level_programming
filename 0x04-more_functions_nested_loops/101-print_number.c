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
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n / 10 != 0)
	{
		print_number(n / 10);
	}
	_putchar(n % 10 + '0');
}
