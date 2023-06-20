#include "main.h"
/**
 * print_alphabet - function that prints the alphabet, in lowercase,
 * follwed by a new line
 *
 * Return:Always 1 success
 */
void print_alphabet(void)
{
	int i;

	for (i = 'a'; i <= 'z'; i++)
	{
		_putchar(i);
	}
	  _putchar('\n');
}
