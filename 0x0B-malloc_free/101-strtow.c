#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>
/**
 * strtow - convert a string to an array of words
 * @str: string to convert
 *
 * Return: pointer to an array of words, or NULL if @str is NULL or empty
 */
extern char **strtow(char *str)
{
	char *p = str;
	char *word;
	char *end = NULL;
	int len;
       	while (isspace(*p) || *p == '\0')
	{
		if (*p == '\0')
		{
			return (NULL);
		}
		p++;
	}
	len = (int)(p - str);
	word = malloc(len + 1);
	if (word == NULL)
	{
		return (NULL);
	}
	*word = '\0';
	end = word + len;
	while (p < end)
	{
		*(word + len) = *p;
		p++;
		if (*p == '\n' || *p == '\r')
		{
			*(word + len + 1) = '\0';
			break;
		}
	}
	*(word + len + 1) = '\0';
	return 0;
}
