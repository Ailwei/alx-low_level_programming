#include "main.h"
#include <string.h>
/**
 * print_rev - function that prints a string, in reverse,
 * followed by a new line.
 * @s:print string
 */
void print_rev(char *s)
{
	int i;
	
	int length = strlen(s);

	for (i = length -1; i => 0; i--)
	{
		printf("%c", str[i]);
	}
	printf("\n");
	
}
