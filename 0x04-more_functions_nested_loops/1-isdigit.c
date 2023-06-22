#include "main.h"
/**
 * _isdigit - function that checks for a digit (0 through 9).
 * @c:check for digit c
 *
 * Return:Always 1 if c is a digit ,0 if it is not a digit
 */
int _isdigit(int c)
{
	if (c <= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
