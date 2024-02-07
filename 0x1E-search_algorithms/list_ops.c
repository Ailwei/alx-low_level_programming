#include "search_algos.h"


/**
 * create_list - Creates a linked list from an array of integers
 * @array: Pointer to the array of integers
 * @size: Size of the array
 *
 * Return: Pointer to the head of the newly created linked list, or NULL if
 * the creation fails
 */
listint_t *create_list(int *array, size_t size)
{
	size_t i;
	listint_t *head = NULL, *current = NULL;

    if (array == NULL || size == 0)
        return (NULL);

    for (i = 0; i < size; i++)
    {
        listint_t *node = malloc(sizeof(listint_t));
        if (node == NULL)
        {
            /* Handle memory allocation failure */
            while (head != NULL)
            {
                listint_t *temp = head->next;
                free(head);
                head = temp;
            }
            return (NULL);
        }

        node->n = array[i];
        node->index = i;
        node->next = NULL;

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

/**
 * print_list - Prints the elements of a linked list
 * @list: Pointer to the head of the linked list
 */
void print_list(const listint_t *list)
{
    const listint_t *current = list;
    printf("List :\n");

    while (current != NULL)
    {
	
        printf("Index[%lu] = [%d]\n", current->index, current->n);
        current = current->next;
    }
    printf("\n");
    
}

/**
 * free_list - Frees the memory allocated for a linked list
 * @list: Pointer to the head of the linked list
 */
void free_list(listint_t *list)
{
    listint_t *current = list;
    listint_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}
