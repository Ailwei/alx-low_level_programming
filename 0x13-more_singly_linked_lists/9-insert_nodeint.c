#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_nodeint_at_index - Inserts a new node at a given position in the list.
 * @head: Double pointer to the head of the list.
 * @idx: Index of the list where the new node should be added.
 * @n: Integer value for the new node.
 *
 * Return: Address of the new node, or NULL if it failed.
 */
struct listint_s *insert_nodeint_at_index(struct listint_s **head, unsigned int idx, int n)
{
    if (head == NULL)
    {
        return NULL; /* Invalid input */
    }

    struct listint_s *new_node = malloc(sizeof(struct listint_s));
    if (new_node == NULL)
    {
        return NULL; /* Memory allocation failed */
    }

    new_node->data = n;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    struct listint_s *current = *head;
    unsigned int current_idx = 0;

    while (current != NULL && current_idx < idx - 1)
    {
        current = current->next;
        current_idx++;
    }

    if (current == NULL || current_idx != idx - 1)
    {
        free(new_node);
        return NULL; /* Invalid index */
    }

    new_node->next = current->next;
    current->next = new_node;

    return new_node;
}

