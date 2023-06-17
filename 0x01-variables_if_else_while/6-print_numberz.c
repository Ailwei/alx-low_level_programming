#include <stdio.h>
/**
 * main - Print all single numbers of 10 starting from 0,
 * followed by a new line
 *
 * Return:Always 0 success
 */
int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
	{
		putchar(number + '0');
		if (number != 9)
			putchar('');
	}
	return (0);
}
