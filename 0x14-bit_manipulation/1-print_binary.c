#include <stdio.h>
#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be converted and printed.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int found_one = 0;

	while (mask > 0)
	{
		if (n & mask)
		{
			putchar('1');
			found_one = 1;
		}
		else if (found_one)
		{
			putchar('0');
		}
		mask >>= 1;
	}

	if (!found_one)
		putchar('0');

	putchar('\n');
}
