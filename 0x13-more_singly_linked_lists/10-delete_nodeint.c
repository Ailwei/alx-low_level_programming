#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - Deletes a node at a given position in the linked list.
 * @head: Pointer to the beginning of the linked list.
 * @index: Index of the node to be deleted.
 * Return: 1 if successful, -1 if fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *previous = NULL;
	unsigned int i;

	if (!current)
		return (-1);
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
		for (i = 0; current && i < index; i++)
		{
			previous = current;
			current = current->next;
		}
		if (!current)
			return (-1);
		previous->next = current->next;
		free(current);
		return (1);
	}

