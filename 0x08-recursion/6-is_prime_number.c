#include "main.h"
#include <math.h>

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: 1 if @n is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}

/**
 * is_prime_helper - Helper function to check for primality recursively.
 * @n: The number to be checked.
 * @divisor: The current divisor being tested.
 *
 * Return: 1 if @n is prime, 0 otherwise.
 */
int is_prime_helper(int n, int divisor)
{
	if (n <= 1)
		return (0);
	if (n == divisor)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime_helper(n, divisor + 1));
}
