#include "main.h"
/**
 * print_triangle - Prints a triangle made of '#' characters.
 * @size: The size of the triangle.
 *
 * Description: This function prints a triangle made of '#' characters,
 * with each row incrementing the number of '#' characters by 1, up to the
 * specified size. If the size is 0 or less, only a new line is printed.
 */
void print_triangle(int size)
{
	int i, j;

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= i; j++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
	if (size <= 0)
	{
		_putchar('\n');
	}
}
