#include "main.h"
/**
 * factorial - Calculates the factorial of a number.
 * @n: The number to calculate the factorial of.
 *
 * Description: This function calculates the factorial of a number 'n'
 *              using recursive approach. If 'n' is lower than 0, it
 *              returns -1 to indicate an error. The factorial of 0 is 1.
 *
 * Return: The factorial of 'n', or -1 if 'n' is lower than 0.
 */
int factorial(int n)
{
	/* Error case: 'n' is lower than 0 */

	if (n < 0)
		return (-1);
	/* Base case: factorial of 0 is 1 */
	if (n == 0)
		return (1);
	/* Recursive call with n-1 */

	 return n * factorial(n - 1);
}
