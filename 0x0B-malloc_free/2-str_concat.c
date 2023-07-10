#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * str_concat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: On success, returns a pointer to the concatenated string.
 *         Returns NULL if memory allocation fails or if either s1 or s2 is NULL.
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated_str;
	unsigned int s1_len, s2_len, concat_len;

	/* Treat NULL strings as empty strings */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	s1_len = strlen(s1);
	s2_len = strlen(s2);
	concat_len = s1_len + s2_len;

	concatenated_str = malloc(sizeof(char) * (concat_len + 1));
	if (concatenated_str == NULL)
		return (NULL);

	strcpy(concatenated_str, s1);
	strcat(concatenated_str, s2);

	return (concatenated_str);
}


