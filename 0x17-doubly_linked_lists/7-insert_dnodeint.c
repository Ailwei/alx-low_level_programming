#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position.
 * @h: A pointer to a pointer to the head of the doubly linked list.
 * @idx: The index at which the new node should be added (starting from 0).
 * @n: The value to be stored in the new node.
 *
 * Return: The address of the new node, or NULL if it failed.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node;
    dlistint_t *current = *h;
    unsigned int i = 0;

    if (h == NULL || (idx != 0 && *h == NULL))
        return (NULL);

    if (idx == 0)
        return (add_dnodeint(h, n));

    while (i < idx - 1)
    {
        if (current == NULL)
            return (NULL);
        current = current->next;
        i++;
    }

    if (current == NULL)
        return (NULL);

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return (NULL);

    new_node->n = n;
    new_node->prev = current;
    new_node->next = current->next;

    if (current->next != NULL)
        current->next->prev = new_node;
    
    current->next = new_node;

    return (new_node);
}

