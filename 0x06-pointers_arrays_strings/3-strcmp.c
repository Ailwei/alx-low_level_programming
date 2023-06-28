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
	int i = 0;

	/* Iterate the strings until a difference is found or the end is reached */
	while (s1[i] == s2[i])
	{
		/* If the end of both strings is reached, they are equal */
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	/* Return the difference between the  characters in s1 and s2 */
	return (s1[i] - s2[i]);
}
