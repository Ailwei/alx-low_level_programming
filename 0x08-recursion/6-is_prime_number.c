#include "main.h"
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

    /* Check for divisibility from 2 to sqrt(n) */
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

