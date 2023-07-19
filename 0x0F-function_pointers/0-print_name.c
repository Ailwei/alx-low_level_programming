#include <stdio.h>

/**
 * print_function - Prints a name.
 * @name: The name to be printed.
 */
void print_function(char *name)
{
	printf("Name: %s\n", name);
}

/**
 * print_name - Calls a function to print a name.
 * @name: The name to be printed.
 * @f: A pointer to the print function.
 */
void print_name(char *name, void (*f)(char *))
{
	f(name);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char name[] = "John Doe";

	print_name(name, print_function);
	return 0;
}

