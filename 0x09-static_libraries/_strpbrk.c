#include "main.h"
#include <stdio.h>

char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (_strchr(accept, *s) != NULL)
		{
			return s;
		}
		s++;
	}
	return NULL;
}

