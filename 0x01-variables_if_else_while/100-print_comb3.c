#include <stdio.h>
/**
 * main - Print all possible dufferent combination
 * of two digits
 *
 * Return:Always 0 success
 */
int main(void)
{
	int two_digits_combo;

	for (two_digits_combo = 0; two_digits_combo <= 99; two_digits_combo++)
		printf("%02d", two_digits_combo);

		if (two_digits_combo != 99)
		{
			putchar(',');
			putchar(' ');

		}

	{
		putchar('\n');
		return (0);

	}
}
