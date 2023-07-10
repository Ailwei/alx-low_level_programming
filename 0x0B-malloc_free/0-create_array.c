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
	unsigned int i;
	char *array;

	if (size == 0)
		return (NULL);
	
	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		array[i] = c;
	return (array);
}

