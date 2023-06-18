#include <stdio.h>
/**
 * main - prints the lowercase alphabet in reverse,
 * follwed by new line.
 *
 * Return:Always 0 success
 */
int main(void)
{
	 /* Print lowercase alphabet in reverse*/
	int alphabet;

	for (alphabet = 'z' ; alphabet >= 'a' ; alphabet--)
	{
		putchar(alphabet);
	}
	/* print new line*/

	putchar('\n');
	return (0);
}
