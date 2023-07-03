#include "main.h"
#include <stddef.h>
/**
 * _strchr - function that locates a character in a string.
 * @s: Pointer to the string to be searched.
 * @c: Character to be located.
 * Return: A pointer to the first occurrence of the character @c
 * in the string @s,or NULL if the character is not found.
 */
char *_strchr(char *s, char c)
{
	/* Iterate through the string until character c is found or end of string */
	while (*s != '\0')
	{
		/* If character c is found, return a pointer to it */
		if (*s == c)
			return (s);
		/* Move to the next character in the string */
		s++;
	}
	/* If character c is not found, return NULL */
	return (NULL);
}
