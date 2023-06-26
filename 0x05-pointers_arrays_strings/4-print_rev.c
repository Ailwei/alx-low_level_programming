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
	char c = 0;

	while (s[c] != '\0')
	{
		c++;
	}
	for (c -= 1; c >= 0; c --)
	{
		putchar(s[c]);
	}
	putchar("%d",'\n');
}
