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

    /* Check if n is divisible by any number from 2 to sqrt(n) */
    if (n == 2 || n == 3)
        return 1;
    if (n % 2 == 0 || n % 3 == 0)
        return 0;

    int divisor;
    int increment;

    while (divisor * divisor <= n)
    {
        if (n % divisor == 0)
            return 0;

        divisor += increment;
        increment = 6 - increment; /* Alternates between 2 and 4 */
    }

    return 1;
}

