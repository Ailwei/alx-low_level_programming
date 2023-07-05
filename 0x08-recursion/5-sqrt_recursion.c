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
