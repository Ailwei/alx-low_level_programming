#include <stdlib.h>

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
	*s = to;
}
