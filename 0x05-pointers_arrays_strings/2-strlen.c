#include "main.h"
/**
 * _strlen - function that returns the length of a string.
 *@s: the length of the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int strlen = 0;

	while (s[strlen] != '\0')
	{
		strlen++;
	}
	return (strlen);
}


