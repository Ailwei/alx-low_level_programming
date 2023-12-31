#include <stddef.h>
#include "dog.h"
/**
 * init_dog - Initializes a struct dog
 * @d: Pointer to the struct dog to initialize
 * @name: Pointer to the name string
 * @age: Age of the dog
 * @owner: Pointer to the owner string
 *
 * Description: This function initializes the fields of the struct dog
 *              pointed to by @d with the provided @name, @age, and @owner.
 */
void init_dog(dog_t *d, char *name, float age, char *owner)
{
	if (d != NULL)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
