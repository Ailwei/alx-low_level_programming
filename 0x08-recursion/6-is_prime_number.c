#include "main.h"

/**
 * is_prime - Checks if a number is prime.
 * @n: The number to check.
 *
 * Return: 1 if the number is prime, 0 otherwise.
 */
int is_prime(int n)
{
	int i;
	if (n <= 1)
		/* Numbers less than or equal to 1 are not prime*/
		return (-1);
	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			/*Found a divisor, not a prime number*/
			return (0);
	}
	return (1); /* No divisors found, it's a prime number*/
}
}
