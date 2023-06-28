#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return:
 *   0 if the strings are equal.
 *   a negative integer if s1 is less than s2.
 *   a positive integer if s1 is greater than s2.
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (int)(unsigned char )(*s) - (int)(unsigned char)(*s2);
}
