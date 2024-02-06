#include "search_algos.h"
/**
 * linear_search - Searches for a value in a sorted array using Binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index where the value is located,
 * or -1 if not present or if array is NULL
 */

int linear_search(int *array, size_t size, int value)
{
	/* Check for NULL array */
	size_t i;

	if (array == NULL)
	{
		printf("Value checked array[0] = [0]\n");
		printf("Array is NULL\n");
		return (-1);
	}
	/* Linear search */
	for (i = 0; i < size; ++i)
	{
		printf("Value checked array[%lu] = [%d]\n", i, array[i]);
		if (array[i] == value)
		{
			/* Value found, return the index*/
			return (i);
		}
	}
	return (-1);
}
