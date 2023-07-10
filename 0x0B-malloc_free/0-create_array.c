#include "main.h"
#include <stdlib.h>

/**
 * create_array - Creates an array of characters and initializes it with a specific character.
 * @size: The size of the array.
 * @c: The character used for initialization.
 *
 * Return: On success, returns a pointer to the array. Returns NULL if size is 0 or if it fails.
 */
char *create_array(unsigned int size, char c)
{
	if (size == 0)
		return (NULL);

	char *array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (unsigned int i = 0; i < size; i++)
		array[i] = c;

	return (array);
}

