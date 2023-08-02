#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the given index of a linked list.
 * @head: A pointer to the head of the linked list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 if the deletion is successful, -1 if it fails.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;

	if (*head == NULL || index < 0)
		return (-1);

	listint_t *current = *head;
	listint_t *temp;

	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}

	for (i = 0; current != NULL && i < index - 1; i++)
	{
		current = current->next;
	}

	if (current == NULL || current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;
	free(temp);
	return (1);
}
