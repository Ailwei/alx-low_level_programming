#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t*ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Create a sorted hash table.
 * @size: The size of the array in the hash table.
 *
 * Return: A pointer to the newly created sorted hash table or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *shash_table;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	shash_table = malloc(sizeof(shash_table_t));
	if (shash_table == NULL)
		return (NULL);
	
	shash_table->size = size;
	shash_table->array = malloc(sizeof(shash_node_t *) * size);
	if (shash_table->array == NULL)
	{
		free(shash_table);
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		shash_table->array[i] = NULL;
	}
	shash_table->shead = NULL;
	shash_table->stail = NULL;
	return (shash_table);
}

/**
 * shash_table_set - Insert a key-value pair into the sorted linked list.
 * @ht: The sorted hash table to insert the pair into.
 * @key: The key to insert.
 * @value: The value to insert.
 *
 * Return: 1 on success, 0 on failure.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node, *prev_node = NULL;
	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}
	new_node->next = NULL;
	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		current_node = ht->shead;
		while (current_node && strcmp(current_node->key, key) < 0)
		{
			prev_node = current_node;
			current_node = current_node->next;
		}
		if (prev_node)
			prev_node->next = new_node;
		else
			ht->shead = new_node;
		new_node->next = current_node;
		if (current_node == NULL)
			ht->stail = new_node;
	}
	return (1);
}

/**
 * shash_table_get - Retrieve a value associated with a key from a sorted hash table.
 * @ht: The sorted hash table to search.
 * @key: The key to look up.
 *
 * Return: The value associated with the given key or NULL if the key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *current_node;

	if (ht == NULL || key == NULL)
		return (NULL);
	current_node = ht->shead;
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Print the sorted hash table in ascending order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current_node;

	if (ht == NULL)
		return;

	printf("{");
	current_node = ht->shead;

	while (current_node != NULL)
	{
		printf("'%s': '%s'", current_node->key, current_node->value);
		if (current_node->next != NULL)
			printf(", ");
		current_node = current_node->next;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Print the sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current_node;
	int comma_flag = 0;

	if (ht == NULL)
		return;
	printf("{");
	current_node = ht->stail;
	while (current_node != NULL)
	{
		if (comma_flag == 1)
			printf(", ");
		printf("'%s': '%s'", current_node->key, current_node->value);
		comma_flag = 1;
		current_node = current_node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Delete the entire sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *next_node;

	if (ht == NULL)
		return;
	current_node = ht->shead;
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = next_node;
	}
	free(ht->array);
	free(ht);
}
