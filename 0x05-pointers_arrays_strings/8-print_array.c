#include <stdio.h>
#include "main.h"
/**
 * Prints n elements of an array of integers, separated by commas and followed by a new line.
 * 
 * @param a     Pointer to the array of integers.
 * @param n     Number of elements to be printed.
 */
void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != n - 1)
		{
			printf(", ");
		}
	}
	printf("\n");
}
