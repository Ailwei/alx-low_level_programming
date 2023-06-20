#include "main.h"
/**
 * print_alphabet_x10 - function that prints 10 times the alphabet,
 * in lowercase, followed by a new line.
 *
 * Return:Always 0 success
 */
void print_alphabet_x10(void)
{
	int i;
	int alphabet;

	for (i = 0; i < 10; i++)
	{
		for (alphabet = 'a'; alphabet <= 'z'; alphabet++)
		{
			 _putchar(alphabet);
		}
		 _putchar('\n');
	
	}
}
