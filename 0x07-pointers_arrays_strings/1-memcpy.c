#include "main.h"
/**
 * _memcpy - Copies a memory area from src to dest.
 * @dest: Pointer to the destination memory area.
 * @src: Pointer to the source memory area.
 * @n: Number of bytes to copy.
 *
 * Return: A pointer to the destination memory area @dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	int i;

	/* Copy each byte from source to destination memory area */

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
