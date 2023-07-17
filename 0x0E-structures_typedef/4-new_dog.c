#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - Creates a new dog
 * @name: Pointer to the name string
 * @age: Age of the dog
 * @owner: Pointer to the owner string
 *
 * Return: Pointer to the newly created dog, or NULL on failure
 *
 * Description: This function creates a new dog with the provided name, age,
 *              and owner. It dynamically allocates memory for the new dog
 *              and copies the name and owner strings. If any memory allocation
 *              fails, NULL is returned.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog = malloc(sizeof(dog_t));

	if (new_dog == NULL)
		return (NULL);
	new_dog->name = malloc(strlen(name) + 1);
	new_dog->owner = malloc(strlen(owner) + 1);
	if (new_dog->name == NULL || new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog->owner);
		free(new_dog);
		return (NULL);
	}
	strcpy(new_dog->name, name);
	strcpy(new_dog->owner, owner);
	new_dog->age = age;
	return (new_dog);
}
