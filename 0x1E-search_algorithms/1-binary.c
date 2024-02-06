#include "search_algos.h"

int binary_search(int *array, size_t size, int value)
{
	size_t i;
	size_t left = 0;
	size_t right = size - 1;
	size_t mid;

	if (array == NULL)
	{
		printf("Searching in arrray: (null)\n");
		return (-1);
	}
	/* print the initial array beeing searched */

	printf("Searching in array: %d", array[0]);
	for (i = 1; i < size; i++)
	{
		printf(",%d", array[i]);
	}
	printf("\n");

	while (left <= right)
	{
		mid = left + (right - left) / 2;
		/* print the currewnt subarray being searched */
		printf("Searching in array: %d", array[left]);
		for (i = left + 1; i <= right; i++)
		{
			printf(", %d", array[i]);
		}
		printf("\n");

		if (array[mid] == value)
		{
			return (mid);
		}
		else if (array[mid] < value)
		{
			left = mid + 1;
		}
		else 
		{
			right = mid + 1;
		}
	}
	return (-1);
}
