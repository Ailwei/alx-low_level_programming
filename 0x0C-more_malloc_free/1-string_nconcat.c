#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes of s2 to concatenate
 *
 * Return: Pointer to the concatenated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0;
	char *concatenated;

	/* Treat NULL strings as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* Calculate the lengths of s1 and s2 */
	len1 = strlen(s1);
	len2 = strlen(s2);
	/* If n is greater or equal to the length of s2, use the entire string */
	if (n >= len2)
		n = len2;
	/* Allocate memory for the concatenated string */
	concatenated = malloc((len1 + n + 1) * sizeof(char));
	if (concatenated == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	/* Copy s1 into the concatenated string */
	strcpy(concatenated, s1);
	/* Append the first n bytes of s2 to the concatenated string */
	strncat(concatenated, s2, n);
	return (concatenated);
}
