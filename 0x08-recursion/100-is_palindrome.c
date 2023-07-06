#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * is_palindrome - Checks if a given string is a palindrome.
 *
 * @s: The string to check.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome(char *s)
{
	int length = strlen(s);

	return (is_palindrome_helper(s, 0, length - 1));
}

/**
 * is_palindrome_helper - Recursive helper function to check
 * if a given string is a palindrome.
 *
 * @s: The string to check.
 * @start: The starting index.
 * @end: The ending index.
 *
 * Return: 1 if the string is a palindrome, 0 otherwise.
 */
int is_palindrome_helper(char *s, int start, int end)
{
	/* Base case: when the start index surpasses the end index8 */
	if (start >= end)
		return (1); /* Palindrome */
	/* Recursive case: check if characters at start and end positions are equal */
	if (s[start] != s[end])
		return (0); /* Not a palindrome */
	/* Move to the next pair of characters */
	return (is_palindrome_helper(s, start + 1, end - 1));
}
