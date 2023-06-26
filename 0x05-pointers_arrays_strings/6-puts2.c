#include "main.h"
#include <stdio.h>
#include <string.h>
/**
 * puts2 -  function that prints every other character of a string'
 * starting with the first character, followed by a new line
 * @str: string parameter
 */
void puts2(char *str)
{
	int i;
	int count = 0;

	int length = strlen(str);

	for (i = 0; i < length; i += 2)
	{
		putchar(str[i]);
		count++;
	}
	printf("\n(%d chars long)\n", count);
}

