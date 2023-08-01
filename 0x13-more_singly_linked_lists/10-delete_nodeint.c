#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * struct listint_s - singly linked list
 * @data: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int data;
    struct listint_s *next;
} listint_t;

/**
 * delete_nodeint_at_index - Deletes the node at index index of a linked list.
 * @head: Pointer to a pointer to the head of the linked list.
 * @index: Index of the node that should be deleted (starts at 0).
 *
 * Return: 1 if successful, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    if (*head == NULL)
        return (-1);

    if (index == 0)
    {
        listint_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return (1);
    }

    listint_t *current = *head;
    listint_t *previous = NULL;
    unsigned int count = 0;

    while (current != NULL)
    {
        if (count == index)
        {
            previous->next = current->next;
            free(current);
            return (1);
        }
        previous = current;
        current = current->next;
        count++;
    }

    return (-1);
}

