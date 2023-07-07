#include <stdio.h>
#include "main.h"

int _strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
		{
			return 0; /* strings are equal */
		}
		i++;
	}
	return s1[i] - s2[i];
}
