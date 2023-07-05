#include "main.h"
#include <stdio.h>
/**
 * _print_rev_recursion - Prints a string in reverse.
 * @s: The string to be printed in reverse.
 *
 * Description: This function recursively prints each character
 *              of the string 's' in reverse order until it reaches
 *              the beginning of the string.
 */

void _print_rev_recursion(char *s)
{
	/* Base case: end of the string */

	if (*s == '\0')
		return;
	 /* Recursively call the function with the next character */

	_print_rev_recursion(s + 1);

	/* Print the current character */

	putchar(*s);


}

