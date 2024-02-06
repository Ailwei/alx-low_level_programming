#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
int binary_searching(int *array, size_t low, size_t high, int value);
void print_array(int *array, size_t low, size_t high);

#endif
