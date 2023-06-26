#include <stdio.h>
#include "main.h"
/**
 * *_strcpy - function that copies the string pointed to by src
 * @(\0): including the terminating null byte (\0),
 * @dest : Return value: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (dest_start);
}

