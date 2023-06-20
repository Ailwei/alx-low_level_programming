#include "main.h"
/**
 * _islower -  function that checks for lowercase character.
 *
 * Return:lowercase 1 success
 * Return:uppercase 0 fail
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else
		return 0;
}
