#include <stdio.h>
#include <stddef.h>
#include "function_pointers.h"
/**
 * print_element - Prints an integer element.
 * @element: The element to be printed.
 */
void print_element(int element)
{
	printf("%d ", element);
}

/**
 * array_iterator - Executes a function on each element of an array.
 * @array: The array of integers.
 * @size: The size of the array.
 * @action: A pointer to the function to be executed on each element.
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		action(array[i]);
	}
}
