#include <stdio.h>
/**
 *main - Prints all numbers of base 16 in lowercase,
 *followed by new line.
 *
 * Return:Always 0 success
 */
int main(void)
{
	int numbers;

	/*print all numbers of base 16 */

	for (numbers = 0; numbers <= 15; numbers++)
	{
		if (numbers < 10)
		{
			putchar(numbers + '0');
		}
		else 
		{
			putchar(numbers - 10 + 'a');
		}
		
	}
	/*prints all */

	putchar('\n');
	return (0);

}
