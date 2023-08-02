#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 * This function can print lists with a loop.
 * It goes through the list only once.
 * If the function fails, it exits the program with status 98.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t count = 0;
    const listint_t *current = head;
    const listint_t *temp;

    while (current != NULL)
    {
        printf("[%p] %d\n", (void *)current, current->n);
        count++;

        temp = current;
        current = current->next;

        if (temp <= current)
        {
            printf("-> [%p] %d\n", (void *)current, current->n);
            printf("-> [%p] %d\n", (void *)temp, temp->n);
            exit(98);
        }
    }

    return count;
}

