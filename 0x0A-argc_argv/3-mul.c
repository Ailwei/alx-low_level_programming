#include <stdio.h>
#include <stdlib.h>

/**
 * multiply_numbers - Multiply two numbers
 * @num1: The first number
 * @num2: The second number
 *
 * Return: The result of the multiplication
 */
int multiply_numbers(int num1, int num2)
{
    return num1 * num2;
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
	int num1, num2, result;

	/* Check if the number of arguments is correct */
	
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	/* Convert command-line arguments to integers */

	num1 = atoi(argv[1]);
       	num2 = atoi(argv[2]);
	
	/* Check if the conversion was successful */
	
	if (num1 == 0 || num2 == 0)
	{
		printf("Error\n");
		return (1);
	}
	/* Multiply the numbers and print the result */
	
	result = multiply_numbers(num1, num2);
	printf("%d\n", result);
	return (0);
}
