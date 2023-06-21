#include <stdio.h>

/**
 * main - Prints the sum of even Fibonacci numbers less than 4,000,000.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int count = 0;
	long previous = 1, current = 2, sum = current;

	while (current + previous < 4000000)
	{
		current += previous;
		if (current % 2 == 0)
			sum += current;
		previous = current - previous;
		count++;
	}
	printf("%ld\n", sum);
	return (0);
}

