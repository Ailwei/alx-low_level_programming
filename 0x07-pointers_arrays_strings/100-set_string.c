#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * set_string - Sets the value of a pointer to a char.
 * @s: Pointer to a pointer to a character.
 * @to: Pointer to a character representing the string to be assigned.
 *
 * Description: This function sets the value of the pointer @s to the string
 *              pointed by @to. If @s is already pointing to a string, the
 *              memory is deallocated before assigning the new string.
 */
void set_string(char **s, char *to)
{
	/* Deallocate memory if the pointer is already pointing to a string */
	if (*s != NULL)
	{
		free(*s);
	}
	/* Allocate memory for the new string */

	*s = malloc((strlen(to) + 1) * sizeof(char));
	/* Copy the contents of the 'to' string to the allocated memory */

	if (*s != NULL)
	{
		strcpy(*s, to);
	}
}

