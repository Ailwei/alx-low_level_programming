#include "main.h"
/**
 */
void times_table(void)
{
	int i;

	for (int i = 0; i <= 10; i++) {
        int result = 9 * i;

        // Print tens digit
        if (result >= 10) {
            _putchar('0' + (result / 10));
        } else {
            _putchar(' ');
        }

        // Print ones digit
        _putchar('0' + (result % 10));

        // Print separator and newline
        _putchar(' ');
        _putchar('x');
        _putchar(' ');
        _putchar('9');
        _putchar(' ');
        _putchar('=');
        _putchar(' ');
        _putchar('0' + result);
        _putchar('\n');
    }

}
