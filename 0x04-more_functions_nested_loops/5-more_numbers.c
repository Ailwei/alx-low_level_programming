#include "main.h"
/**
 */
void more_numbers(void)
{
	int i, j;

	char numbers[] = "01234567891011121314";
	for (j = 0; j < 10; j++)
	{
		for (i = 0; i < 17; i++)
		{
			_putchar(numbers[i]);
		}
		_putchar('\n');
	}
}
