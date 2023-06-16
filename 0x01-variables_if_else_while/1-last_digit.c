#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main -This program will assign a random number to the variable n each time it is executed 
 * 
 */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 5)
	{
	printf("%d is greater than 5\n", n);
	}
	else if (n == 0)
	{
	printf("%d and is 0\n", n);
	}
	else if (n < 6 && n != 0)
       	{
	printf("%d and is less than6 and not 0\n", n);
	}
	return (0);
}
