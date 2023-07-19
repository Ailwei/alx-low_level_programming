#include "function_pointers.h"
#include <stddef.h>

/**
 * int_index - Searches for an integer in an array.
 * @array: The array of integers to be searched.
 * @size: The number of elements in the array.
 * @cmp: A pointer to the function used for comparison.
 *
 * Return: The index of the first matching element, or -1 if no match or invalid size.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array && cmp && size > 0)
	{
		for (i = 0; i < size; i++)
		{
			if (cmp(array[i]) != 0)
				return (i);
		}
	}

	return (-1);
}

