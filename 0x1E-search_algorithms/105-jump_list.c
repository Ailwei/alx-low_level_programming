#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted linked list of integers
 * using the Jump search algorithm.
 *
 * @head: Pointer to the head of the linked list
 * @size: Number of nodes in the linked list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located or
 * if value is not present in head or if head is NULL, return NULL
 */
listint_t *jump_list(listint_t *head, size_t size, int value)
{
    listint_t *current =  NULL, *next_block = NULL;
    size_t jump = 0;

    if (head != NULL)
    {
        current = head;
        next_block = head;
        while (next_block->next != NULL && next_block->index < size && next_block->n < value)
        {
            current = next_block;
            jump += sqrt(size);
            while (next_block->index < jump && next_block->next != NULL)
                next_block = next_block->next;
            printf("Value checked at index [%lu] = [%d]\n", next_block->index, next_block->n);
        }
        printf("Value found between indexes [%lu] and [%lu]\n",
               current->index, next_block->index);
        while (current != NULL && current->index < size && current->index <= next_block->index)
        {
            printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
            if (current->n == value)
                return (current);
            current = current->next;
        }
    }
    return (NULL);
}
