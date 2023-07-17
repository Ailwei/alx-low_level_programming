#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Structure representing information about a dog
 * @name: Pointer to a string representing the dog's name
 * @age: Floating-point number representing the dog's age
 * @owner: Pointer to a string representing the dog's owner
 *
 * Description: This structure holds information about a dog,
 *              including its name, age, and owner.
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;
#endif /* DOG_H */
