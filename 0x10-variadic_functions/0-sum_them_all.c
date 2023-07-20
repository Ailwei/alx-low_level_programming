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
	va_list ap;
	unsigned int param, sum = 0;

	/* initialize the argument list from the start */
	va_start(ap, n);

	/* iterate through all parameter values*/
	for (param = 0; param < n; param++)
		/* get the next parameter value and add it to sum*/
		sum += va_arg(ap, int);
	/*Clean up*/
	va_end(ap);

	return (sum);
}
