#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    size_t index;
    struct listint_s *next;
} listint_t;


int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_searching(int *array, size_t low, size_t high, int value);
void print_array(int *array, size_t low, size_t high);
int advanced_binary(int *array, size_t size, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);

listint_t *create_list(int *array, size_t size);
void print_list(const listint_t *list);
void free_list(listint_t *list);

#endif
