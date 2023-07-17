#include <stdio.h>
#include "dog.h"
#include <stdlib.h>
/**
 * print_dog - Prints the details of a struct dog
 * @d: Pointer to the struct dog to print
 *
 * Description: This function prints the contents of the struct dog
 *              pointed to by @d. If any element of @d is NULL,
 *              "(nil)" is printed instead of that element.
 *              If @d is NULL, nothing is printed.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;
	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.1f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}
