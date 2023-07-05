/**
 * _sqrt_recursion - Calculates the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Description: This function calculates the natural square root of
 *              a number 'n' using recursive approach. If 'n' does not
 *              have a natural square root, it returns -1.
 *
 * Return: The natural square root of 'n', or -1 if 'n' does not have
 *         a natural square root.
 */
int _sqrt_recursion(int n)
{
	/* Error case: 'n' is negative */

	if (n < 0)
		return (-1);

	/* Base case: square root of 0 or 1 is the number itself */

	if (n == 0 || n == 1)
		return n;
	/* Call a helper function with additional parameters */

	return _sqrt_helper(n, 1, n);
}
/**
 * _sqrt_helper - Helper function to find the square root using binary search.
 * @n: The number to calculate the square root of.
 * @start: The starting value of the search range.
 * @end: The ending value of the search range.
 *
 * Return: The square root of 'n', or -1 if 'n' does not have a natural square root.
 */
int _sqrt_helper(int n, int start, int end)
{
	int mid = (start + end) / 2;

	if (start <= end)
	{
		/* Check if the middle value is the square root */

		if (mid * mid == n)
			return mid;
		/* If the middle value is greater, search in the lower half */
		else if (mid * mid > n)
			return _sqrt_helper(n, start, mid - 1);
		/* If the middle value is smaller, search in the upper half */
		return _sqrt_helper(n, mid + 1, end);
	}
	/* Error case: 'n' does not have a natural square root */
	return -1;
}
