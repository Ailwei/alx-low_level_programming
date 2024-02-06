#include "search_algos.h"

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where the value is located,
 * or -1 if not found or array is NULL
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t i;
	int index;

	if (array == NULL || size == 0)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
		else
			printf("\n");
	}

	if (size == 1 && array[0] != value)
		return (-1);

	index = size / 2;

	if (array[index] == value)
	{
		for (i = index; i > 0 && array[i - 1] == value; i--)
		return (i);
	}

	if (array[index] < value)
	{
		int result = advanced_binary(array + index, size - index, value);

		return (result == -1 ? -1 : result + index);
	}

	/* Add handling for the case where array[index] > value */
	return (advanced_binary(array, index, value));
}
