#include "main.h"
#include <stddef.h>
#include <stdio.h>
/**
 * _strspn - Gets the length of a prefix substring.
 * @s: Pointer to the string to be searched.
 * @accept: Pointer to the string of characters to be matched.
 *
 * Return: The number of bytes in the initial segment of @s consisting only
 *         of bytes from @accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;
	int i;

	while (*s)
	{
		found =0;

		 /* Iterate through the accept string to check if the character is present */

		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				found = 1;
				break;
			}
		}
		if (found)
			count++;
		else
			break;
		s++;

	}
	return (count);

}
