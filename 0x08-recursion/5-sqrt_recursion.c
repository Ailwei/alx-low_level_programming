#include "main.h"
/**
 * _sqrt_recursion - Computes the natural square root of a number.
 * @n: The number to compute the square root of.
 *
 * Return: The natural square root of @n, -1
 * if @n does not have a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0 || n == 1)
		return (n);
	return  (_sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - Helper function to compute the square root recursively.
 * @n: The number to compute the square root of.
 * @start: The starting point for the search.
 * @end: The ending point for the search.
 *
 * Return: The natural square root of @n
 * within the given range, -1 if not found.
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid;

	if (start <= end)
	{
		mid = (start + end) / 2;
		if (mid * mid == n)
			return (mid);
		if (mid * mid < n)
			return (_sqrt_helper(n, mid + 1, end));
		return (_sqrt_helper(n, start, mid - 1));
	}
	return (-1); /* Square root not found */
}
