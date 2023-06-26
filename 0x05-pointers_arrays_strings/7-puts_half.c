#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * puts_half - function that prints half of a string, followed by a new line.
 * @str: function should print the second half of the string
 * Return: If the number of characters is odd, the function should print the last n characters of the string
 */

void puts_half(char *str)
{
	int length = strlen(str);
	int start_index;

	if (length % 2 == 0)
	{
		start_index = length / 2;
	}
	else
	{
		start_index = (length - 1) / 2;
	}
	printf("%s\n", str + start_index);
}
