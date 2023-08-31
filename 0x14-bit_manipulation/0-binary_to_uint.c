#include <stddef.h> /* for NULL definition */
#include "main.h"

/**
 * binary_to_uint - Convert a binary number to an unsigned int.
 * @b: A pointer to a string containing binary digits (0 and 1).
 *
 * Return: The converted number, or 0
 * if there's an invalid character in the string or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int bit;

	if (b == NULL)
		return (0);

	while (*b != '\0')
	{
		if (*b != '0' && *b != '1')
			return (0);

		bit = *b - '0'; /* Convert char '0' or '1' to an unsigned int (0 or 1) */
		result = (result << 1) | bit;
		b++; /* Move to the next character in the string */
	}

	return (result);
}
