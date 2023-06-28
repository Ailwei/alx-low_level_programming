#include "main.h"
#include <stdio.h>
/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: Pointer to the resulting string `dest`.
 */

char *_strcat(char *dest, char *src)
{
	char *destPtr = dest;

	/* Move the destination pointer to the end of the string */

	while (*destPtr)
	{
		destPtr++;
	}
	/* Append the source string to the destination */

	while (*src)
	{
		*destPtr = *src;
		destPtr++;
		src++;
	}
	/* Add a terminating null byte */
	dstPtr = '\0';
	return (dest);
}

