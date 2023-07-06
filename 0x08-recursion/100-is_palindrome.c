#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * Checks if a given string is a palindrome.
 *
 * @param s The string to check.
 * @return 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = strlen(s);
	int i, j;
	
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])
		{
			return (0); /* Not a palindrome */
		}
	}
	return (1); /* Palindrome */
}
