#include <stdio.h>
#include "main.h"

/**
 * print_diagsums - Prints the sum of the two diagonals of a square matrix.
 * @a: Pointer to the start of the matrix.
 * @size: Size of the square matrix.
 *
 * Description: This function calculates and prints the sum of the two diagonal
 * of a square matrix of integers.The matrix is represented by a one-dimensional
 * array of size size * size, where each row is contiguous in memory.
 * The sum of the main diagonal is printed first, followed by the sum of the
 * secondary diagonal, each separated by a comma and a space.
 */
void print_diagsums(int *a, int size)
{
	int i, sum_main_diag = 0, sum_secondary_diag = 0;
	/* Calculate the sum of the main diagonal and the secondary diagonal */
	for (i = 0; i < size; i++)
	{
		sum_main_diag += a[i * size + i];
		sum_secondary_diag += a[i * size + (size - i - 1)];
	}
	/* Print the sums */
	printf("%d, %d\n", sum_main_diag, sum_secondary_diag);
}
