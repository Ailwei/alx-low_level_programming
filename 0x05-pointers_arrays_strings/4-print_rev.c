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
	int i;
	int length = strlen(s);
	for (i = length; i < length; length++)
	{
		continue;
	}

	for (i = length - 1; i <= 0; i--)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
