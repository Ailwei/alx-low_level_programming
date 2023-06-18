#include <stdio.h>
/**
 * main - print all possible different 
 * combinations of three digits
 *
 * Return:Always 0 success
 */
int main(void)
{
	int digitcombo;
	for (digitcombo = 0; digitcombo <= 9; digitcombo++)
	{
		putchar(digitcombo + '0');
		if (digitcombo != 9)
		{
			putchar(',');
			putchar(' ');
		}
	}
	 putchar('\n');
	 return (0);
}
