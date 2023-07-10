#include <stdio.h>
nclude "main.h"

/**
 * main - Entry point of the program.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	char *concatenated_args = argstostr(argc - 1, argv + 1);

	if (concatenated_args == NULL)
	{
		printf("Failed to concatenate arguments.\n");
		return (1);
	}
	printf("Concatenated arguments:\n%s\n", concatenated_args);
	free(concatenated_args);  /* Remember to free the allocated memory */
	return (0);
}
