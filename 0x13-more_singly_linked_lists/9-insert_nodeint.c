#include <stdlib.h>
#include "lists.h"

/**
 * free_listint - frees a listint_t linked list
 * @head: pointer to the head of the list
 */
void free_listint(struct listint_s *head)
{
	struct listint_s *current = head;
	struct listint_s *next_node;

	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}
