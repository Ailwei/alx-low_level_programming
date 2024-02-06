#include "search_algos.h"

int linear_search(int *array, size_t size, int value)
{
	/* Check for NULL array */
	 size_t i;
	 if (array == NULL)
	 {
		 printf("Value checked array[0] = [0]\n");
		 printf("Array is NULL\n");
		 return (-1);
	 }
	 /* Linear search */
	 for (i = 0; i < size; ++i)
	 {
		 printf("Value checked array[%lu] = [%d]\n", i, value);
		 if (array[i] == value)
		 {
			 /* Value found, return the index*/
			 return (i);
		 }
	 }
	 return (-1);
}
