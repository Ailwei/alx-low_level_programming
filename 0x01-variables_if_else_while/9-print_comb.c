#include <stdio.h>
/**
 * main - print all possible combinations
 * of single-digit numbers
 *
 * Return:Always 0 success
 */
int main(void)
{
	int single_digit_combo;

	for (single_digit_combo = 0; single_digit_combo <= 9; single_digit_combo++)
	{
		putchar(single_digit_combo + '0');
		putchar(' , ' + '\n');
	}
	putchar('\n');
	return (0);
}
