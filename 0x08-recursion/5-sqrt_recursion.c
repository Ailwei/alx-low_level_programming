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
    int sqrtN;
    int i;

    if (n <= 1)
        return (0);

    if (n == 2)
        return (1);

    if (n % 2 == 0)
        return (0);

    sqrtN = sqrt(n);
    for (i = 3; i <= sqrtN; i += 2)
    {
        if (n % i == 0)
            return (0);
    }

    return (1);
}

