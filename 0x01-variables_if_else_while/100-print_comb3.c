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
	int count=0;


    for (two_digits_combo = 0; two_digits_combo <= 99; two_digits_combo++)
    {
        if (two_digits_combo % 10 > two_digits_combo / 10)
        {
            if (count > 0)
            {
                putchar(',');
                putchar(' ');
            }

            if (two_digits_combo < 10)
                putchar('0');

            printf("%d", two_digits_combo);

            count++;
        }
    }

    putchar('\n');
    return 0;
}
