#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index index of a linked list
 * @head: pointer to the beginning of the linked list
 * @index: index of the node to be deleted (starting from 0)
 * Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	listint_t *current = *head;
	listint_t *prev = NULL;
	unsigned int i = 0;

	/* Handle special case: delete the first node */
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	/* Traverse to find the node at the specified index or the end of the list */
	while (current != NULL && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	/* If index is out of bounds, return -1 (failed) */
	if (current == NULL)
		return (-1);

	/* Perform the deletion by updating the pointers and freeing the node */
	prev->next = current->next;
	free(current);
	return (1);
}

