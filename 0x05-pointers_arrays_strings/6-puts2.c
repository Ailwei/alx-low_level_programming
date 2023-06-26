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
	int i = 0;
	while (str[i] != '\0')
	{
		putchar(str[i]);
		i += 2;
	}
	putchar('\n');
}

