#include <stdio.h>
/**
 * main -Print all single digit of bas 10
 * starting from 0, followed by a new line
 *
 * Return:Always 0 successful
 */

int main(void)
{
	int number;

	for (number = 0; number < 10; number++)
	{
		putchar('0' + number);
	}
	putchar('\n');
	return (0);
}
