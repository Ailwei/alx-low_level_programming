#include "main.h"
#include <stdio.h>
#include <math.h>

/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Description: This function calculates the natural square root of
 *              a number 'n' using a recursive approach. If 'n' does not
 *              have a natural square root, it returns -1.
 *
 * Return: The natural square root of 'n', or -1 if 'n' does not have
 *         a natural square root.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0 || n == 1)
		return (n);
	else
		return (_sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - Helper function to find the square root using binary search.
 * @n: The number to calculate the square root of.
 * @start: The starting value of the search range.
 * @end: The ending value of the search range.
 *
 * Description: This function performs a binary search to find the square root
 *              of a number within a given range. If the square root is found,
 *              it returns the value. Otherwise, it returns -1.
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid, square;

	if (start > end)
		return (-1);

	int mid = start + (end - start) / 2;
	int square = mid * mid;

	if (square == n)
		return (mid);
	else if (square > n)
		return (_sqrt_helper(n, start, mid - 1));
	else
		return (_sqrt_helper(n, mid + 1, end));
}

