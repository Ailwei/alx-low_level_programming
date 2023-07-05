#include "main.h"
#include <stdio.h>
/**
 * _puts_recursion - function that prints a string, followed by a new line.
 *@s: The string to be printed.
 *
 * Description:This function recursively prints each character
 *  of the string 's' until it reaches the end and
 *  prints a new line character.
 */

void _puts_recursion(char *s)
{
	/* Base case: end of the string */

	if (*s == '\0')
	{
		putchar('\n');
		return;
	}
	/* Print the current character */

	putchar(*s);

	 /* Recursively call the function with the next character */
	_puts_recursion(s + 1);
}
