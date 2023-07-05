#include "main.h"
#include <math.h>

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to check.
 *
 * Description: This function checks whether a given number 'n' is prime or not.
 *              It returns 1 if the number is prime, and 0 otherwise.
 *
 * Return: 1 if 'n' is prime, 0 otherwise.
 */
int is_prime_number(int n)
{
    /* 0 and 1 are not prime numbers */
    if (n <= 1)
        return 0;

    /* Check for divisibility by numbers up to sqrt(n) */
    return is_prime_helper(n, 2);
}

/**
 * is_prime_helper - Helper function to check for prime recursively.
 * @n: The number to check.
 * @divisor: The current divisor to check divisibility.
 *
 * Return: 1 if 'n' is prime, 0 otherwise.
 */
int is_prime_helper(int n, int divisor)
{
    /* Base case: n is divisible by the divisor */
    if (n % divisor == 0)
        return 0;

    /* Base case: All possible divisors have been checked */
    if (divisor * divisor > n)
        return 1;

    /* Recursive case: Check the next divisor */
    return is_prime_helper(n, divisor + 1);
}

