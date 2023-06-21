#include "main.h"
#include <stdio.h>
/**
 */
void print_to_98(int n)
 
    for (int i = n; i <= 98; i++) {
        printf("%d", i);

        
        if (i != 98) {
            printf(", ");
        }
    }

    printf("\n");
} 

