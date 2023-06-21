#include "main.h"
/**
 * print_last_digit - Prints the last digit of a number
 * @number: Number to be treated
 *
 * Return: Value of the last digit of number
 */

int _last_digit(int number)
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
