#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * _calloc - Allocates memory for an array and sets it to zero
 * @nmemb: The number of elements in the array
 * @size: The size of each element in bytes
 *
 * Return: Pointer to the allocated memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    void *ptr;
    unsigned int total_size;

    /* Check for zero nmemb or size */
    if (nmemb == 0 || size == 0)
        return NULL;

    /* Calculate the total size to allocate */
    total_size = nmemb * size;

    /* Allocate memory using malloc */
    ptr = malloc(total_size);

    if (ptr == NULL)
        return NULL;

    /* Set the allocated memory to zero using memset */
    memset(ptr, 0, total_size);

    return ptr;
}

