#include "main.h"
#include <string.h>
/**
 * rev_string - function that reverses a string
 * @s: parameter string
 */
void rev_string(char *s)
{
	int start = 0;

	int end = strlen(s) - 1;

	while (start < end)
	{
		char temp = s[start];

		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}
