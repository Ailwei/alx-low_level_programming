#include "main.h"
#include <stdio.h>

/**
 * print_chessboard - Prints the chessboard.
 * @a: 2D array representing the chessboard.
 *
 * Description: This function takes a 2D array representing a chessboard
 * and prints its contents. Each element of the array represents a square
 * on the chessboard and is printed character by character.
 */
void print_chessboard(char (*a)[8])
{
	int i, j;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			putchar(a[i][j]);/* Print the character at position (i, j) */
		}
		putchar('\n');  /* Move to the next line after printing each row */
	}
}
