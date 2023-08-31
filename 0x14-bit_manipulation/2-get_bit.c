#include "main.h"
#include <stdio.h>

/**
 * get_bit - Get the value of  bit at a given index.
 * @n: The unsigned long integer to extract the bit from.
 * @index: The index of the bit to retrieve (starting from 0).
 *
 * Return: The value of the bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask;

	if (index >= sizeof(unsigned long int) * 8)
	{
		/* Index out of bounds */
		return (-1);
	}

	mask = 1UL << index;
	return ((n & mask) ? 1 : 0);
}

