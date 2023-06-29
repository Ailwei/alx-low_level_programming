#include <string.h>
#include "main.h"

/**
 * leet - Encodes a string into 1337
 * @str: The input string
 *
 * Return: Pointer to the modified string
 */
char *leet(char *str)
{
	int i, j;

	/* Corresponding replacement characters for "aAeEoOtTlL" */
	char leetChars[5] = "43071";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' ||
					str[i] == 'o' || str[i] == 'O' || str[i] == 't' ||
					str[i] == 'T' || str[i] == 'l' || str[i] == 'L')
			{
				str[i] = leetChars[j];
				break;
			}
		}
	}
	return (str);
}
