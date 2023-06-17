#include <stdio.h>
/**
 * main - Print the alphabet in lowercase
 * followed by a new line
 *
 * Return: Always 0 success
 */
int main(void)
{
	int i;
	/*Print all the letters except q and e */
	for (i = 'a'; i <= 'z'; i++)
	{
		if (i != 'q' && i != 'e')
		{
			putchar(i);
		}
	}
		putchar('\n');
		return (0);
	}

