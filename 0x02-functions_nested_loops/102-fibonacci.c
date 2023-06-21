#include <stdio.h>

void fibonacci_sequence(int n) {
    int sequence[50];
    sequence[0] = 1;
    sequence[1] = 2;
    
    printf("%d, %d", sequence[0], sequence[1]);
    
    int i;
    for (i = 2; i < n; i++) {
        sequence[i] = sequence[i-1] + sequence[i-2];
        printf(", %d", sequence[i]);
    }
    
    printf("\n");
}

int main() {
    fibonacci_sequence(50);
    
    return 0;
}

