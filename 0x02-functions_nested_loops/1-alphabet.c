#include "main.h"
/**
 * main - function that prints the alphabet, in lowercase,
 * follwed by a new line
 *
 * Return:Always 1 success
 */
void print_alphabet(void)
{
	int alphabet;
	for (alphabet =26; alphabet <= 26;alphabet++)
	{
		_putchar('%2' alphabet);
		_putchar('\n');
	}
}
