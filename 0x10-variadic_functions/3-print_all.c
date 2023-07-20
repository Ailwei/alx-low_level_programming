#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - Prints anything based on the format provided.
 * @format: A list of types of arguments passed to the function.
 *
 * Return: void
 * Print a new line at the end of the function.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	const char *fmt_ptr = format;
	char c_val;
	int i_val;
	float f_val;
	char *s_val;

	va_start(args, format);

	while (format && *fmt_ptr)
	{
		if (*fmt_ptr == 'c')
		{
			c_val = va_arg(args, int);
			printf("%c", c_val);
		}
		else if (*fmt_ptr == 'i')
		{
			i_val = va_arg(args, int);
			printf("%d", i_val);
		}
		else if (*fmt_ptr == 'f')
		{
			f_val = va_arg(args, double);
			printf("%f", f_val);
		}
		else if (*fmt_ptr == 's')
		{
			s_val = va_arg(args, char *);
			if (s_val == NULL)
				printf("(nil)");
			else
				printf("%s", s_val);
		}
		fmt_ptr++;

		if (*fmt_ptr && (*fmt_ptr == 'c' || *fmt_ptr == 'i' || *fmt_ptr == 'f' || *fmt_ptr == 's'))
			printf(", ");
	}

	va_end(args);
	printf("\n");
}
