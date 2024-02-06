#include "search_algos.h"
/**
 * binary_search - Searches for a value in a sorted array using Binary Search
 * @array: Pointer to the first element of array to search in
 * @size: Number of elements in the array
 * @value: The va;lue to search for
 *
 * Return: Index where value is lacated
 * or  -1 if not present or array is NULL
*/

int binary_search(int *array, size_t size, int value)
{
	size_t left = 0, i, right = size - 1, mid;

	if (array == NULL || size == 0)
		return (-1);

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		printf("Searching in array: ");
		for (i = left; i <= right; i++)
		{
			printf("%d", array[i]);
			if (i < right)
				printf(", ");
			else
				printf("\n");
		}
		if (array[mid] == value)
			return (mid);
		if (array[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}
