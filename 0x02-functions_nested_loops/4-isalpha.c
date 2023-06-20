#include "main.h"
/**
 * _isalpha - function that checks for alphabetic character.
 *checks for alphabetic character
 *
 * Return:1 if it is alphabetic ,0 if not
 */
int _isalpha(int c)
{
	if ((c = 'a' && c <= 'z') || (c = 'A' && <= 'Z'))
		return (1);
	else
		return (0);
	       	

}
