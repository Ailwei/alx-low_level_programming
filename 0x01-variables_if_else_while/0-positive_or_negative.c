#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/**
 * main -assign a random number to int n everytime it execute
 * and print it
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
	{
	printf("%d is positive \n", n);
	}
	else if (n == 0)
	{
	printf("%d is zero\n", n);
	}
	else if (n < 0)
	{
	printf("%d is negative\n", n);
	}
	return (0);
}
