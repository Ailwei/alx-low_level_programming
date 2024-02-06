#include "search_algos.h"

/**
 * exponential_search - Searches for a value
 * in a sorted array using Exponential search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located,
 * or -1 if not found or array is NULL
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;
	size_t low, high;

	if (array == NULL || size == 0)
		return (-1);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}
	low = bound / 2;
	high = (bound < size - 1) ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_searching(array, low, high, value));
}

/**
 * binary_searching - Searches for a value in
 * a sorted array using Binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @low: Lowest index of the array to search in
 * @high: Highest index of the array to search in
 * @value: Value to search for in the array
 *
 * Return: The first index where value is located, or -1 if not found
 */
int binary_searching(int *array, size_t low, size_t high, int value)
{
	size_t mid;

	while (low <= high)
	{
		printf("Searching in array:");
		print_array(array, low, high);

		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

/**
 * print_array - Prints the elements of an array between the given indices
 * @array: Pointer to the first element of the array
 * @low: Lowest index of the array to print
 * @high: Highest index of the array to print
 */
void print_array(int *array, size_t low, size_t high)
{
	size_t i;

	for (i = low; i <= high; i++)
	{
		if (i == low)
			printf(" %d", array[i]);
		else
			printf(", %d", array[i]);
	}
	printf("\n");
}
