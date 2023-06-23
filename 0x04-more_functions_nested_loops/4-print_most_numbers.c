#include "main.h"
/**
 * print_most_numbers - print numbers from 0 to 9
 * Description: prints numbers excluding 2 and 4
 * Return:The numbers since 0 up to 9
 */

void print_most_numbers(void)
{
	char n;

	for (n = '0'; n <= '9'; n++)
	{
		if (!(n == '2' || n == '4'))
			_putchar(n);
	}
	_putchar('\n');
}
