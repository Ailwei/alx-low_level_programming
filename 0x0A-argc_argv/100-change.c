#include <stdio.h>
#include <stdlib.h>

/**
 * calculate_minimum_coins - Calculate the minimum number of coins for change
 * @cents: The amount of money in cents
 *
 * Return: The minimum number of coins needed for change
 */
int calculate_minimum_coins(int cents)
{
	int coins = 0;

	if (cents <= 0)
	{
		return (0);
	}
	/* Greedy approach: Subtract the largest possible coin value */
	while (cents >= 25)
	{
		cents -= 25;
		coins++;
	}
	while (cents >= 10)
	{
		cents -= 10;
		coins++;
	}
	while (cents >= 5)
	{
		cents -= 5;
		coins++;
	}
	while (cents >= 2)
	{
		cents -= 2;
		coins++;
	}
	coins += cents;  /* Add remaining cents as 1 cent coins */
	return (coins);
}

/**
 * main - Entry point of the program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{

	int cents, result;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
	}
	else
	{
		result = calculate_minimum_coins(cents);
		printf("%d\n", result);
	}
	return (0);
}
