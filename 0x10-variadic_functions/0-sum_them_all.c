#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"
/**
 * sum_them_all - Returns the sum of all its parameters.
 * @n: The number of arguments passed.
 * @...: Variable number of arguments.
 *
 * Return: The sum of all the arguments.
 * If n == 0, return 0.
 */
int sum_them_all(const unsigned int n, ...)
{
	if (n == 0)
		return (0);

	int sum = 0;

	va_list args;
	va_start(args, n);

	for (unsigned int i = 0; i < n; ++i)
		sum += va_arg(args, int);

	va_end(args);

	return (0);
}
