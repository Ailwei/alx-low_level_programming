#include "main.h"
/**
 * print_numbers - prints the numbers, from 0 to 9, followed by a new line
 *
 * Return: Always 0 success
 */
void print_numbers(void)
{
	int numbers;

	for (numbers = 0; numbers <10; numbers++)
	{
		_putchar('0' + numbers);
	}
	_putchars('\n');
}
