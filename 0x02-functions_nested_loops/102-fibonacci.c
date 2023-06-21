#include <stdio.h>
/**
 * main - prints the sum of even fibonacci numbers
 * less than 5000000.
 * Return: Nothing!
 */
int main(void)
{
	int counter = 0;
	long prevNum = 1, currNum = 2, sum = currNum;

	while (currNum + prevNum < 4000000)
	{
		currNum += prevNum;
		if (currNum % 2 == 0)
			sum += currNum;
		prevNum = currNum - prevNum;
		counter++;
	}

	printf("%ld\n", sum);
	return (0);
}
