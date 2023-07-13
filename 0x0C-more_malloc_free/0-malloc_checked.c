#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * malloc_checked - Allocates memory using malloc
 * @b: The number of bytes to allocate
 *
 * Return: Pointer to the allocated memory
 * If malloc fails, the function causes process termination with status 98
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	/* Attempt to allocate memory using malloc */
	ptr = malloc(b);

	/* Check if malloc succeeded */
	if (ptr == NULL)

		/* Terminate the process with status 98 */
		exit(98);

	/* Return the allocated memory pointer */
	return (ptr);
}

