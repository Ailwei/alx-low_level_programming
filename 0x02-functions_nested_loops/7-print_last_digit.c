#include "main.h"
/**
 * Print_last_digit - prints the last digit of a number
 * @number: number to be treated
 * Return: Value of the last digit of number
 */
int print_last_digit(int number)
{
	int last;

	last = number % 10;

	if (last < 0)
	{
		last = last * -1;
	}
	_putchar(last + '0');
	return (last);
}
