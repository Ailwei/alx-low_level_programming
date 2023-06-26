#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * print_rev - function that prints a string, in reverse,
 * followed by a new line.
 * @s:print string
 */
void print_rev(char *s)
{
	int length = strlen(s);

	for (int i = length - 1; i >= 0; i--)
	{
		putchar(s[i]);
	}
	putchar('\n');
}
