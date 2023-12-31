#include "main.h"
#include <stdio.h>

/**
 * wildcmp - Compares two strings considering the special character '*'.
 *
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		/* Base case: both strings are empty, they are considered identical */
		return (1);
	}
	if (*s1 == *s2 || *s2 == '*')
	{
		if (*s2 == '*' && *(s2 + 1) == '\0')
		{
			/* If s2 has single wildcard '*',it matches the remaig s1 */
			return (1);
		}
		if (*s1 != '\0')
		{
			if (wildcmp(s1 + 1, s2 + 1) == 1)
				return (1);
		}
		if (*s2 == '*')
		{
			if (wildcmp(s1, s2 + 1) == 1)
				return (1);
		}
	}
	return (0); /* Characters don't match and string doesn't have a wildcard */
}
