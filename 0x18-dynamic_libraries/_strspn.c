#include "main.h"
#include <stddef.h>

/**
 * custom_strchr - Locates the first occurrence of character 'target' in string 'str'.
 * @str: The string to search in.
 * @target: The character to locate.
 *
 * Return: A pointer to the first occurrence of 'target' in 'str', or NULL if 'target' is not found.
 */
char *custom_strchr(char *str, char target)
{
	if (str == NULL)
		return (NULL);

	while (*str != target)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
