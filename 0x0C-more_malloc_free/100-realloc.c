#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the memory block to reallocate
 * @old_size: Size of the currently allocated space in bytes
 * @new_size: New size of the memory block in bytes
 *
 * Return: Pointer to the reallocated memory block, or NULL on failure
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	/* If ptr is NULL, equivalent to malloc(new_size) */
	if (ptr == NULL)
		return (malloc(new_size));
	/* If new_size is zero, equivalent to free(ptr) */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	/* If new_size is equal to old_size, do nothing and return ptr */
	if (new_size == old_size)
		return (ptr);
	/* Allocate memory for the new size using malloc */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	/* Copy the contents of the old block to the new block */
	if (new_size > old_size)
		memcpy(new_ptr, ptr, old_size);
	else
		memcpy(new_ptr, ptr, new_size);
	/* Free the old memory block */
	free(ptr);
	return (new_ptr);
}
