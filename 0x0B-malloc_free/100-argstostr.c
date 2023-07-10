#include "main.h"
#include <stdlib.h>
#include <string.h>

char *argstostr(int ac, char **av) {
    int total_length = 0;
    int position = 0;
    int i, j;
    char *result;

    if (ac == 0 || av == NULL) {
        return NULL;
    }

    /* Calculate the total length of the concatenated string */
    for (i = 0; i < ac; i++) {
        total_length += strlen(av[i]) + 1;  /* +1 for newline character */
    }

    /* Allocate memory for the concatenated string */
    result = (char *)malloc((total_length + 1) * sizeof(char));
    if (result == NULL) {
        return NULL;  /* Failed to allocate memory */
    }

    /* Concatenate the arguments with newlines */
    for (i = 0; i < ac; i++) {
        for (j = 0; av[i][j] != '\0'; j++) {
            result[position++] = av[i][j];
        }
        result[position++] = '\n';
    }

    result[total_length] = '\0';  /* Replace the last newline with null terminator */

    return result;
}
