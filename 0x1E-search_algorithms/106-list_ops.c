#include "search_algos.h"


skiplist_t *create_skiplist(int *array, size_t size)
{
	/* Function declaration */
	skiplist_t *head = NULL, *current = NULL;
	size_t i;

	/* Function implementation */

	if (array == NULL || size == 0)
		return (NULL);
	for (i = 0; i < size; i++)
	{
		skiplist_t *node = malloc(sizeof(skiplist_t));

		if (node == NULL)
		{
			/* Handle memory allocation failure */
			while (head != NULL)
			{
				skiplist_t *temp = head->next;

				free(head);
				head = temp;
			}
			return (NULL);
		}
		/* Initialize the new node */
		node->n = array[i];
		node->index = i;
		node->next = NULL;
		node->express = NULL;

		/* Update pointers */
		if (head == NULL)
		{
			head = node;
			current = head;
		}
		else
		{
			current->next = node;
			current = current->next;
		}
	}
	return (head);
}
void print_skiplist(const skiplist_t *list)
{
	/* Function declaration */
	const skiplist_t *current = list;

	/* Function implementation */
	printf("List :\n");
	while (current != NULL)
	{
		printf("Index[%lu] = [%d]\n", current->index, current->n);
		current = current->next;
	}
	printf("\n");
}

void free_skiplist(skiplist_t *list)
{
	/* Function declaration */
	skiplist_t *current = list;
	skiplist_t *next;
	
	/* Function implementation */
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
