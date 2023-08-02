#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the beginning of the linked list
 * @idx: index where to insert
 * @n: value for n
 * Return: address of new node or NULL if fails
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i = 0;

	if (idx == 0)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = *head;
		*head = new_node;

		return (*head);
	}

	temp = *head;
	while (temp && i < idx - 1)
	{
		temp = temp->next;
		i++;
	}

	if (temp)
	{
		new_node = malloc(sizeof(listint_t));
		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = temp->next;
		temp->next = new_node;

		return (new_node);
	}

	return (NULL);
}


