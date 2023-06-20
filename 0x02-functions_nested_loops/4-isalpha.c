#include "main.h"
/**
 * _isalpha - function that checks for alphabetic character.
 *checks for alphabetic character
 *
 * Return:1 if it is alphabetic ,0 if not
 */
int _isalpha(int c)
{
	   int is_alpha = 0;

    for (; c >= 'A' && c <= 'Z'; c++)
    {
        is_alpha = 1;
        break;
    }

    for (; c >= 'a' && c <= 'z'; c++)
    {
        is_alpha = 1;
        break;
    }

    return is_alpha;
}
