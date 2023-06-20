#include "main.h"
/**
 * _isalpha - function that checks for alphabetic character.
 *checks for alphabetic character
 *
 * Return:1 if it is alphabetic ,0 if not
 */
int _isalpha(int c)
{
	   int i;

    for (i = 'a'; i <= 'z'; i++)
    {
        if (c == i)
            return 1;
    }

    for (i = 'A'; i <= 'Z'; i++)
    {
        if (c == i)
            return 1;
    }

    return 0;
}
}
