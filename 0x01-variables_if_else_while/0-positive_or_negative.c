#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/* This program will assign a random number to the variable n each time it is executed. Complete the source code in order to print whether the number stored in the variable n is positive or negative.
 * */
int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	/* your code goes there */
	if (n > 0)
		printf("Positive");
	else if (n < 0)
		printf("Negative");
	else if(n == 0 )
		printf("Zero");
	return (0);
}
