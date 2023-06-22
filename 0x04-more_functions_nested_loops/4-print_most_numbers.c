#include "main.h"
/**
 * print_most_numbers - print numbers from0 to 9,
 * follwed by a new line
 * @2: dont print 2,
 * @4: dont print 4
 *
 *Return:Always 0 success
 */
void print_most_numbers(void)
{
	int numbers;

	for (; numbers <= 9; numbers++)
	{
		if (numbers == 2 || numbers == 4)
		{
			continue;
		}
		else
		{
			_putchar(numbers + '0');
		}	
	}
	_putchar('\n');
}
