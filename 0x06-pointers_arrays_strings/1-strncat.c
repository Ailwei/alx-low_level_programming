#include "main.h"

/**
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to be used from src.
 *
 * Return: Pointer to the resulting string `dest`.
 */
char *_strncat(char *dest, const char *src, int n)
{
	char *destPtr = dest;

	/* Move the destination pointer to the end of the string */
	while (*destPtr)
	{
		destPtr++;
	}

	/* Append the source string to the destination, using at most n bytes */
	while (*src && n > 0)
	{
		*destPtr = *src;
		destPtr++;
		src++;
		n--;
	}

	/* Add a terminating null byte */
	*destPtr = '\0';

	return (dest);
}
