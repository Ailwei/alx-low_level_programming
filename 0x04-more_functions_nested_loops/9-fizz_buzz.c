#include <stdio.h>
/**
 * main - Entry point of the program.
 *
 * Description: Prints  from 1 to 100, replacing multiples of 3 with "Fizz",
 * multiples of 5 with "Buzz", and multiples of both 3 and 5 with "FizzBuzz".
 *
 * Return: Always 0 (indicating success).
 */
int main(void)
{
	int y;

	for (y = 1; y <= 100; y++)
	{
		if ((y % 3 == 0) && (y % 5 == 0))
		{
			printf("FizzBuzz");
		}
		else if (y % 3 == 0)
		{
			printf("Fizz");
		}
		else if (y % 5 == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("%d", y);

		}
		if (y != 100)
		{
			printf(" ");
		}
	}
	printf("\n");
	return (0);
}
