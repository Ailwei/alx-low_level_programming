#include "main.h"
/**
 * _isalpha - function that checks for alphabetic character.
 *@c:checks for alphabetic character
 *
 * Return:1 if it is alphabetic ,0 if not
 */
int _isalpha(int c)
{
	int is_alpha = 0;

	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		is_alpha = 1;

	return (is_alpha);
}
