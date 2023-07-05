#include "main.h"
#include <math.h>

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The square root of @n, or -1 if no natural square root exists.
 */
int _sqrt_recursion(int n)
{
	return (_sqrt_recursive_helper(n, 0, n));
}

/**
 * _sqrt_recursive_helper - Helper function for calculating the square root recursively.
 * @n: The number to calculate the square root of.
 * @start: The starting point of the range to search for the square root.
 * @end: The ending point of the range to search for the square root.
 *
 * Return: The square root of @n within the given range, or -1 if not found.
 */
int _sqrt_recursive_helper(int n, int start, int end)
{
	if (start > end)
		return (-1);

	int mid = start + (end - start) / 2;
	int square = mid * mid;

	if (square == n)
		return (mid);
	else if (square < n)
		return (_sqrt_recursive_helper(n, mid + 1, end));
	else
		return (_sqrt_recursive_helper(n, start, mid - 1));
}
