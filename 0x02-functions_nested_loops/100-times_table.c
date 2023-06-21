#include "main.h"
#include <stdio.h>
/**
 */
void print_times_table(int n)
{
	if (n > 15 || n < 0)
	{
		return;
	}
	int i;

	for (i = 0; i <= 10; i++)
	{
		 printf("%d x %d = %d\n", i, n, i * n);
	}
}
