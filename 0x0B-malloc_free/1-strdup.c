#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strdup - Duplicates a string.
 * @str: The string to be duplicated.
 *
 * Return: On success, returns a pointer to the duplicated string.
 *         Returns NULL if str is NULL or if insufficient memory was available.
 */
char *_strdup(char *str)
{
	char *dup_str;

	if (str == NULL)
		return (NULL);

	dup_str = malloc(sizeof(char) * (strlen(str) + 1));
	if (dup_str == NULL)
		return (NULL);

	strcpy(dup_str, str);

	return (dup_str);
}

