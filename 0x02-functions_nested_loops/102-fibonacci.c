#include <stdio.h>
/**
 * main - prints the sum of even fibonacci numbers
 * less than 5000000.
 * Return: Nothing!
 */

void fibonacci_sequence(int n) {
    int sequence[5000000];
    int i;

    sequence[0] = 1;
    sequence[1] = 2;
    
    printf("%d, %d", sequence[0], sequence[1]);
    
    
    for (i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
        printf(", %d", sequence[i]);
    }
    
    printf("\n");
}

int main() {
    fibonacci_sequence(5000000);
    
    return 0;
}

