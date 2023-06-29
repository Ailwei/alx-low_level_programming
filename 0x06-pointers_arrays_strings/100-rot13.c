#include <stdlib.h>
#include <string.h>

/**
 * rot13 - Encodes a string using the ROT13 cipher.
 * @str: The input string to be encoded.
 *
 * Return: A newly allocated string containing the encoded result.
 *         The caller is responsible for freeing the memory.
 */
char *rot13(char *str)
{
	char *result;
	int i, j;
	char c;

	result = malloc(sizeof(char) * (strlen(str) + 1));
	if (result == NULL)
		return (NULL);

	for (i = 0, j = 0; str[i] != '\0'; i++, j++)
	{
		c = str[i];

		/* Apply ROT13 transformation */
		if (c >= 'a' && c <= 'z')
		{
			c = ((c - 'a') + 13) % 26 + 'a';
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = ((c - 'A') + 13) % 26 + 'A';
		}

		result[j] = c;
	}

	result[j] = '\0';

	return (result);
}

