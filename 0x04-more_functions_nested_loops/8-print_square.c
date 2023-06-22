#include "main.h"
/**
 * print_square - Prints a square of '#' characters.
 * @size: The size of the square.
 *
 * Description: This function prints a square of '#' characters
 * with the specified size. If size is 0 or less, it prints only
 * a new line character.
 */
void print_square(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
