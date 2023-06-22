#include "main.h"
/**
 * print_line -  draws a straight line in the terminal.
 * @n: Where n is the number of times the character _ should be printed
 */
void print_line(int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		_putchar('_');
	}
	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		_putchar('\n');

	}
}
