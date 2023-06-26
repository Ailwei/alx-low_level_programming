#include "main.h"
#include <stdio.h>
#include <string.h>

void puts_half(char *str)
{
	int length = strlen(str);
	int start_index;
	if (length % 2 == 0)
	{
		start_index = length / 2;
	}
	else
	{
		start_index = (length - 1) / 2;
	}
	printf("%s\n", str + start_index);
}
