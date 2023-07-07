#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * add_positive_numbers - Add positive numbers
 * @numbers: An array of strings containing the numbers
 * @count: The number of elements in the array
 *
 * Return: The sum of the positive numbers, or -1 on error
 */
int add_positive_numbers(char *numbers[], int count)
{
	int i, sum = 0;

	for (i = 0; i < count; i++)
	{
		int j;

		/* Check if the string contains only digits */
		for (j = 0; numbers[i][j] != '\0'; j++)
		{
			if (!isdigit(numbers[i][j]))
			{
				return (-1);
			}
		}
		sum += atoi(numbers[i]);
	}
	return (sum);
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
	if (argc == 1)
	{
		printf("0\n");
	}
	else
	{

		int sum = add_positive_numbers(argv + 1, argc - 1);

		if (sum == -1)
		{
			printf("Error\n");
			return (1);
		}
		printf("%d\n", sum);
	}
	return (0);
}
