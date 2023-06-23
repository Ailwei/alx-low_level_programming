#include "main.h"
/**
 * print_most_numbers - print numbers from 0 to 9
 * Description: prints numbers excluding 2 and 4
 * Return:The numbers since 0 up to 9
 */

void print_most_numbers(void)
{
	int numbers;

	for (numbers = 0; numbers <= 9; numbers++)
	{
		if (!(numbers == 2 || numbers == 4))
			_putchar(numbers);
	}
	_putchar('\n');
}
