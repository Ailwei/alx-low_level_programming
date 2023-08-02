#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list safely.
 * @h: Double pointer to the beginning of the linked list.
 * Return: The number of nodes in the list.
 */

size_t free_listint_safe(listint_t **h)
{
	int i = 0;
	listint_t *slow, *fast, *delete;

	if (h == NULL || *h == NULL)
		return (0);

	while (*h != NULL)
	{
		slow = *h;
		fast = (*h)->next;

		/* Detect loop using Floyd's cycle-finding algorithm */
		while (fast != NULL && fast->next != NULL)
		{
			if (slow == fast)
			{
				/* Loop detected, break the loop and free nodes */
				fast = NULL;
				break;
			}
			slow = slow->next;
			fast = fast->next->next;
		}

		delete = *h;
		*h = (*h)->next;
		free(delete);
		i++;
	}

	return (i);
}

