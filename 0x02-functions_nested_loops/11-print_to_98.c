#include "main.h"
#include <stdio.h>
/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The number to start printing from
 * Return: Always 0.
 */
void print_to_98(int n)
{

        if (n <= 98) {
        for (int i = n; i <= 98; i++) {
            printf("%d", i);

            
            if (i != 98) {
                printf(", ");
            }
        }
    } 
    else {
        for (int i = n; i >= 98; i--) {
            printf("%d", i);

            if (i != 98) {
                printf(", ");
            }
        }
    }

    printf("\n");  
}
