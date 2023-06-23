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
	if (size <= 0)
	{
		_putchar('\n');
	}
	int row, col;
	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= row; col++)
		{
			_putchar('#');
        }
		_putchar('\n');
	}
}
