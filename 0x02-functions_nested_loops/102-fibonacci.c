#include <stdio.h>
/**
 * main - prints the sum of even fibonacci numbers
 * less than 5000000.
 * Return: Nothing!
 */
int main(void)
{
	int counter = 0;    /* Counter variable */
	long prevNum = 1, currNum = 2, sum = currNum;    /* Variables for Fibonacci sequence and sum */

	while (currNum + prevNum < 4000000)
	{
		currNum += prevNum;    /* Generate the next Fibonacci number */
		if (currNum % 2 == 0)
			sum += currNum;    /* Accumulate even Fibonacci numbers */
		prevNum = currNum - prevNum;    /* Update the previous Fibonacci number */
		counter++;    /* Increment the counter */
	}

	printf("%ld\n", sum);    /* Print the sum of even Fibonacci numbers */
	return (0);
}
