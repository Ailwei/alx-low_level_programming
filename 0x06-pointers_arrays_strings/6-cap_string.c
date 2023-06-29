#include "main.h"
#include <ctype.h>
#include <string.h>

/**
 * cap_string - Capitalizes all words in a string
 * @str: The input string
 *
 * Return: Pointer to the modified string
 */
char *cap_string(char *str)
{
	int length = strlen(str);
	int capitalize = 1;

	for (int i = 0; i < length; i++)
	{
		/* Check if current character is a separator */
		if (isspace(str[i]) || str[i] == ',' || str[i] == ';' || str[i] == '.' ||
		    str[i] == '!' || str[i] == '?' || str[i] == '"' || str[i] == '(' ||
		    str[i] == ')' || str[i] == '{' || str[i] == '}')
		{
			capitalize = 1; /* Set flag to capitalize next character */
		}
		else if (capitalize)
		{
			str[i] = toupper(str[i]); /* Capitalize the current character */
			capitalize = 0; /* Reset flag to not capitalize subsequent characters */
		}
	}

	return (str);
}

