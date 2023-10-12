#include "lists.h"
/**
 * dlistint_len - Returns the number of elements in dlistint list
 * @h: A pointer to the head of the double linked
 *
 * Return: The number of number of thein the last
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}
