#include "main.h"
#include <stdio.h>

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	while (*s != '\0' && _strchr(accept, *s) != NULL)
	{
		count++;
		s++;
	}
	return count;
}

