#include "main.h"
/**
 * _isupper - function that checks for uppercase character.
 * @c: if c is uppercase
 *
 * Return: Always 1 if is upper case ,0 if not uppercase.
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
