#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - A singly linked list node.
 * @n: Integer data for the node.
 * @next: Pointer to the next node in the list.
 *
 * Description: A structure to represent a node in a singly linked list.
 */

/* Define the listint_t structure representing a linked list node */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

/* Function prototype to print all elements of a listint_t list */
size_t print_listint(const listint_t *h);
size_t listint_len(const listint_t *h);

#endif
