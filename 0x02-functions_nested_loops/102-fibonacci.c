#include <stdio.h>
/**
 * main - prints the sum of even fibonacci numbers
 * less than 
 * Return: Nothing!
 */
int main(void)
{
	int i;
	long prevNum = 1, currNum = 2;
	printf("%ld, %ld", prevNum, currNum);
	for (i = 2; i < 50; i++)
	{
		long nextNum = prevNum + currNum;
		printf(", %ld", nextNum);
		prevNum = currNum;
		currNum = nextNum;
	}
	printf("\n");
	return 0;
}
