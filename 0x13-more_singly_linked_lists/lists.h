#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Define the listint_t structure representing a linked list node */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototype to print all elements of a listint_t list */
size_t print_listint(const listint_t *h);

#endif
