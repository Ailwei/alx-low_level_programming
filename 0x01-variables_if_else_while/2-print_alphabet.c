#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the alphabet in lowercase, followed by a new line
 *
 * Return 0 on success
 */


int main(void)
{
	int i;
		for (i = 0; i < 26; i++)
		{
			putchar('a'+ i);
		}
	putchar('\n');
	return (0);
}

