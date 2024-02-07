#include "search_algos.h"


/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located,
 * or NULL if list is NULL or value not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current, *express_lane;

	if (!list)
		return (NULL);

	current = list;
	express_lane = list;

	while (express_lane->express && express_lane->n < value)
	{
		current = express_lane;
		express_lane = express_lane->express;
		printf("Value checked at index [%lu] = [%d]\n",
				express_lane->index, express_lane->n);
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, express_lane->index);
	while (current->next && current->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				current->index, current->n);
		current = current->next;
	}
	printf("Value checked at index [%lu] = [%d]\n",
			current->index, current->n);
	if (current->n == value)
	{
		printf("Found %d at index: %lu\n", value, current->index);
		return (current);
	}
	else
	{
		printf("%d not found\n", value);
		return (NULL);
	}
}
