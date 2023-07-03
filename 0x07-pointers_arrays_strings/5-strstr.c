#include <stddef.h>
#include "main.h"
/**
 * _strstr - Locates a substring.
 * @haystack: Pointer to the string to be searched.
 * @needle: Pointer to the substring to be located.
 *
 * Return: A pointer to the beginning of the located substring in @haystack,
 *         or NULL if the substring is not found.
 */
char *_strstr(char *haystack, char *needle)
{
	/* Check if needle is empty, return haystack */
	if (*needle == '\0')
		return (haystack);

	while (*haystack)
	{
		char *n = needle;
		char *h = haystack;

		while (*n && *h == *n)
		{
			h++;
			n++;
		}

		/* Compare characters of haystack and needle */
		if (*n == '\0')
			return (haystack);
		haystack++;
	}
	/* Substring not found */
	return (NULL);
}
