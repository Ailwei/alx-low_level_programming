#include "main.h"
/**
 * rev_string - function that reverses a string
 * @s:
 */
void rev_string(char *s)
{
	int start = 0;
	int end = strlen(input_string) - 1;

	while (start < end)
	{
		char temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
}
