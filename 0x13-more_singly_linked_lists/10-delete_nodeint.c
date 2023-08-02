#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes a node at a given position
 * @head: pointer to the beginning of linked list
 * @index: index to be deleted
 * Return: 1 if successful, -1 if fails
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (*head == NULL)
		return (-1);

	/* Special case: delete the first node */
	if (index == 0)
	{
		listint_t *temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	listint_t *prev = NULL;
	listint_t *current = *head;
	unsigned int i = 0;

	/* Traverse the list to find the node at the specified index */
	while (current != NULL && i < index)
	{
		prev = current;
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1); /* Index is out of bounds */

	/* Perform the deletion by updating the pointers */
	prev->next = current->next;
	free(current);
	return (1);
}

