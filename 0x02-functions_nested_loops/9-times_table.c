#include "main.h"

/**
 * times_table - prints the 9 times table, starting with 0
 */
void times_table(void) {
    int i, j;

    for (i = 0; i <= 9; i++) {
        for (j = 0; j <= 9; j++) {
            int result = i * j;

            // Print tens digit
            if (result >= 10) {
                _putchar('0' + (result / 10));
            } else {
                _putchar(' ');
            }

            // Print ones digit
            _putchar('0' + (result % 10));

            // Print separator
            _putchar(',');

            // Print space
            _putchar(' ');
        }

        // Print newline
        _putchar('\n');
    }
}
