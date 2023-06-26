#include <stdio.h>

int _atoi(char *s) {
    int sign = 1;
    int result = 0;
    int i = 0;

    // Skip any leading whitespace
    while (s[i] == ' ')
        i++;

    // Check for a sign
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    // Convert digits to integer until a non-digit character is encountered
    while (s[i] >= '0' && s[i] <= '9') {
        // Check for overflow
        if (result > (INT_MAX - (s[i] - '0')) / 10) {
            // Handle overflow by returning the maximum or minimum value based on the sign
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
}
